#include <iostream>
using namespace std;

bool isprime(int val){
    for (int i = 2; i<= val/2 ;i++){
        if ((float(val/i)) == (float(val)/i)){
            return false;
        }
    }
    return true;
}

int main(){
    for (int i = 2; i<=20; i++){
        cout << i << ": " << isprime(i)<< endl;
    }
    return 0;
}