#include <iostream>
#include <cuda_runtime.h>

#define BLOCK_SIZE 16  // You can try 32 on high-end GPUs

// Tiled matrix multiplication kernel using shared memory
__global__ void matMulTiled(float *A, float *B, float *C, int N) {
    // Shared memory tiles for A and B
    __shared__ float tile_A[BLOCK_SIZE][BLOCK_SIZE];
    __shared__ float tile_B[BLOCK_SIZE][BLOCK_SIZE];

    // Row and column of the C element
    int row = blockIdx.y * BLOCK_SIZE + threadIdx.y;
    int col = blockIdx.x * BLOCK_SIZE + threadIdx.x;

    float sum = 0.0f;

    // Loop over all tiles
    for (int m = 0; m < (N + BLOCK_SIZE - 1) / BLOCK_SIZE; ++m) {
        // Load one tile of A into shared memory
        if (row < N && (m * BLOCK_SIZE + threadIdx.x) < N) {
            tile_A[threadIdx.y][threadIdx.x] = A[row * N + m * BLOCK_SIZE + threadIdx.x];
        } else {
            tile_A[threadIdx.y][threadIdx.x] = 0.0f;
        }

        // Load one tile of B into shared memory
        if (col < N && (m * BLOCK_SIZE + threadIdx.y) < N) {
            tile_B[threadIdx.y][threadIdx.x] = B[(m * BLOCK_SIZE + threadIdx.y) * N + col];
        } else {
            tile_B[threadIdx.y][threadIdx.x] = 0.0f;
        }

        __syncthreads();  // Ensure all threads have loaded their data

        // Compute partial product
        for (int k = 0; k < BLOCK_SIZE; ++k) {
            sum += tile_A[threadIdx.y][k] * tile_B[k][threadIdx.x];
        }

        __syncthreads();  // Ensure all threads have finished using the tiles
    }

    // Write result
    if (row < N && col < N) {
        C[row * N + col] = sum;
    }
}

void randomInit(float *data, int size) {
    for (int i = 0; i < size; ++i)
        data[i] = static_cast<float>(rand() % 100) / 10.0f;
}

int main() {
    int N = 1024; // Matrix size (N x N)
    size_t size = N * N * sizeof(float);

    // Allocate host memory
    float *h_A = new float[N*N];
    float *h_B = new float[N*N];
    float *h_C = new float[N*N];

    // Initialize matrices
    randomInit(h_A, N*N);
    randomInit(h_B, N*N);

    // Allocate device memory
    float *d_A, *d_B, *d_C;
    cudaMalloc((void**)&d_A, size);
    cudaMalloc((void**)&d_B, size);
    cudaMalloc((void**)&d_C, size);

    // Copy host to device
    cudaMemcpy(d_A, h_A, size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_B, h_B, size, cudaMemcpyHostToDevice);

    // Grid and block dimensions
    dim3 threadsPerBlock(BLOCK_SIZE, BLOCK_SIZE);
    dim3 blocksPerGrid((N + BLOCK_SIZE - 1) / BLOCK_SIZE,
                       (N + BLOCK_SIZE - 1) / BLOCK_SIZE);

    // Launch kernel
    matMulTiled<<<blocksPerGrid, threadsPerBlock>>>(d_A, d_B, d_C, N);
    cudaDeviceSynchronize();

    // Copy result back to host
    cudaMemcpy(h_C, d_C, size, cudaMemcpyDeviceToHost);

    std::cout << "Optimized (tiled shared memory) matrix multiplication completed!" << std::endl;

    // Cleanup
    delete[] h_A;
    delete[] h_B;
    delete[] h_C;
    cudaFree(d_A);
    cudaFree(d_B);
    cudaFree(d_C);

    return 0;
}
