#include <stdio.h>
#include <stdlib.h>
// function takes in array and size. 
// returns nothing

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

void countingsort(int* arr, int size){
    int maximum = max_finder(arr, size)+1;
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
    int arr[] = {5,9,2,8,4,2,12,5,1,7,4,7,12,7,4,12,85,34,72,223,34,346,243,3,43,5,32,43,4,34,43,56,34,3,7,2,9,365,325,2,2,4,45,78,2,34,4};
    int size = sizeof(arr)/sizeof(int);
    printf("%d \n", max_finder(arr, size));

    printall(arr,size);
    countingsort(arr,size);
    printall(arr,size);
    return 0;

}