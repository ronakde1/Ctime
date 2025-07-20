#include <stdio.h>
#include <math.h>
typedef struct  {
    int n;
    int x;
} radix_pair;
radix_pair pos_generator(int n, int pos){
    int x = (n / ((int)pow(10,pos)))%10;
    radix_pair pair = {n, x};
    return pair;
}

int main(){
    int intlst[] = {100,120,123};
    radix_pair pairlst[3] = {0,0};
    for (int i = 0; i < 3; i++){
        pairlst[i] = pos_generator(intlst[i],0);
    }
    radix_pair hi = pos_generator(123,2);
    // printf("%d \n", hi.n);
    // printf("%d \n", hi.x);
    //  hi = pos_generator(123,1);
    // printf("%d \n", hi.x);
    //  hi = pos_generator(123,0);
    // printf("%d \n", hi.x);
    printf("%d \n", pairlst[2].n);
    printf("%d \n", pairlst[2].x);
    return 0;
}