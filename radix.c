#include <stdio.h>
#include <stdlib.h>
// function takes in array and size. 
// returns nothing
struct radix_pair {
    int n;
    int x;
};
void radixsort(int* arr, int size){
    int max_val = max_finder(arr, size);
    int n_iterations = ceil(log10(max_val));
    

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
void printall(int* arr, int size){
    for (int i = 0;i<size;i++){
        printf("%d,",arr[i]);
    }
    printf("\n");
}

void countingsort(int* arr, int size, int base){
    int maximum = base;
    int* p = calloc(maximum, sizeof(int));
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
    int arr[] = {5,9,2,8,4,2,2,1,5,3,8};
    int size = sizeof(arr)/sizeof(int);

    printall(arr,size);
    countingsort(arr,size,10);
    printall(arr,size);
    return 0;

}