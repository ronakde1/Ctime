#include <iostream>
using namespace std;

template <typename T> class Stack{
    T val;
    Stack* nextptr;
    public:
    Stack(T value):val(value), nextptr(nullptr){}
    Stack(T value, Stack* ptr): val(value), nextptr(ptr) {}
    Stack(const Stack& s):val(s.val),nextptr(nullptr){

        if (s.nextptr){
            Stack* current = this;
            Stack* tocopy = s.nextptr;
            while (tocopy){
                current->nextptr = new Stack(tocopy -> val);
                current = current -> nextptr;
                tocopy = tocopy -> nextptr;
            }
        }
    }
    Stack& operator=(const Stack& s){
        if (this == &s){
            return *this;
        }
        Stack* current = nextptr;
        while (current) {
            Stack* next = current->nextptr;
            current->nextptr = nullptr; 
            delete current;
            current = next;
        }
        nextptr = nullptr;
        Stack* newcurrent = this;
        Stack* tocopy = s.nextptr;
        val = s.val;
        while (tocopy){
            newcurrent->nextptr = new Stack(tocopy->val);
            newcurrent = newcurrent -> nextptr;
            tocopy = tocopy -> nextptr;
        }
        return *this;
    }




    void add(T element){
        nextptr = new Stack(val,nextptr);
        val = element;
    }
    T pop(){
        T oldvalue = val;
        if (nextptr){
            Stack* oldptr = nextptr;
            val = nextptr -> val;
            nextptr = nextptr -> nextptr;
            delete oldptr;
        } else{
            val = -1;
        }
        return oldvalue;
    }
    void printall() const {
        cout << val;
        Stack* current = nextptr;
        while (current){
            cout << current -> val;
            current = current -> nextptr;
        } 
        cout << endl;
    }
    ~Stack() {
        Stack* current = nextptr;
        while (current) {
            Stack* next = current->nextptr;
            current->nextptr = nullptr; 
            delete current;
            current = next;
        }
    }
};
int main(){
    Stack hi(1);
    hi.add(2);
    hi.add(3);
    hi.add(4);
    hi.add(5);
    hi.add(6);
    hi.add(7);
    hi.printall();
    Stack hi2 = hi;
    hi2.printall();

    return 0;
}