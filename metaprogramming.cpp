#include <iostream>

template <unsigned int n, unsigned int acc = 1>
struct fact {
    enum { value = fact<n - 1, acc * n>::value };
};

template <unsigned int acc>
struct fact<0, acc> {
    enum { value = acc };
};


template <int n, int testval = n/2>
struct prime {
    enum {value = (n%testval != 0) && prime<n, testval -1>::value};
};

template <int n>
struct prime<n, 2> {
    enum { value = (n%2 != 0) };
};
template <int n>
struct prime<n, 1> {
    enum { value = true };
};



bool isprime(int val){
    for (int i = 2; i<= val/2 ;i++){
        if ((float(val/i)) == (float(val)/i)){
            return false;
        }
    }
    return true;
}

 int main() {
    std::cout << 2 << ": "<< prime<2>::value << std::endl;
    std::cout << 3 << ": "<< prime<3>::value << std::endl;
    std::cout << 4 << ": "<< prime<4>::value << std::endl;
    std::cout << 5 << ": "<< prime<5>::value << std::endl;
    std::cout << 6 << ": "<< prime<6>::value << std::endl;
    std::cout << 7 << ": "<< prime<7>::value << std::endl;
    std::cout << 8 << ": "<< prime<8>::value << std::endl;
    std::cout << 9 << ": "<< prime<9>::value << std::endl;
    std::cout << 10 << ": "<< prime<10>::value << std::endl;
    std::cout << 11 << ": "<< prime<11>::value << std::endl;
    
 
}