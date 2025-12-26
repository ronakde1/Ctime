#include <iostream>

class rectangle{
    public: 

    int height;
    int width;
    rectangle(int h, int w){
        height = h;
        width = w;
    }
    
    
    
    int getArea() {
        return height * width;
    }
};
int main(){
    rectangle newrec = rectangle(3,2);
    std::cout << newrec.getArea();

    return 0;
}