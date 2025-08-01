#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// function takes in array and size. 
// returns nothing
typedef struct  {
    int n;
    int x;
} radix_pair;
void printall(int* arr, int size){
    for (int i = 0;i<size;i++){
        printf("%d,",arr[i]);
    }
    printf("\n");
}
radix_pair pos_generator(int n, int pos){
    int x = (n / ((int)pow(10,pos)))%10;
    radix_pair pair = {n, x};
    return pair;
}
int max_finder(int* arr, int size){
    int maximum = arr[0];
    for (int i = 0; i < size; i++){
        if (maximum < arr[i]){
            maximum=arr[i];
        }
    }
    return maximum;
}
void radixsort(int* arr, int size){
    int max_val = max_finder(arr, size);
    int n_iterations = ceil(log10(max_val));
    for (int pos = 0; pos <= n_iterations; pos ++){
        int **intermediate = (int **)malloc(10 * sizeof(int *));
        for (int i = 0; i < 10; ++i) {
            intermediate[i] = (int *)calloc(size, sizeof(int));
        }

        int posarr[10] = {0};
        radix_pair *arr_pair = (radix_pair *)calloc(size, sizeof(radix_pair));
        for (int i = 0; i < size; i++){
            arr_pair[i] = pos_generator(arr[i],pos);
        }

        for (int i = 0; i < size; i++) {
            int digit = arr_pair[i].x;
            intermediate[posarr[digit]++][digit] = arr_pair[i].n;
        }
        printf("hi");
        for (int i = 0; i < size; i++){
            printall(intermediate[i],10);
        }
        printf("\n");

        int index = 0;
        for (int i = 0; i < 10; i++){
            for (int j = 0; j < posarr[i]; j++){
                arr[index++] = intermediate[i][j];
            }
        }

        free(arr_pair);
        free(intermediate);
        printall(arr,size);
    }
}


void countingsort(int* arr, int size){
    int maximum = max_finder(arr, size)+1;
    int* p = (int*) calloc(maximum, sizeof(int));
    for (int i = 0; i< size; i++){
        p[arr[i]]++;
    }
    //printall(p,maximum);
    int index = 0;
    int pos = 0;
    while (index < maximum){
        if (p[index] > 0){
            arr[pos++] = index;
            p[index]--;
        }
        else{
            index++;
        }
    }

    return;
}


int main(){
    printf("hello world \n");
    int arr[] = {1,2,4,25,34,16,19};
    int size = sizeof(arr)/sizeof(int);

    printall(arr,size);
    //countingsort(arr,size,10);
    radixsort(arr,size);
    printall(arr,size);
    int arr2[] = {1,2,4,25,34,16};
    countingsort(arr2,size);
    printall(arr2,size);
    return 0;
    

}
