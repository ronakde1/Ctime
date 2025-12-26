#include <iostream>
using namespace std;

template<int n, int testval = n/2> struct primecheck{
    enum{ value = (n%testval != 0) && primecheck<n, testval-1>::value};
};
template<int n> struct primecheck<n,2>{
    enum {value = (n%2 != 0)};
};
template<int n> struct primecheck<n,1>{
    enum {value = true};
};

int main(){
    cout << primecheck<2>::value;
    cout << primecheck<3>::value;
    cout << primecheck<4>::value;
    cout << primecheck<5>::value;
    cout << primecheck<6>::value;
    cout << primecheck<7>::value;
    cout << primecheck<8>::value;
    cout << primecheck<9>::value;
    return 0;
}