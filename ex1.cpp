/*
Write an implementation of a class LinkList which stores zero or
more positive integers internally as a linked list on the heap. The
class should provide appropriate constructors and destructors and a
method pop() to remove items from the head of the list. The method
pop() should return -1 if there are no remaining items. Your
implementation should override the copy constructor and assignment
operator to copy the linked-list structure between class instances. You
might like to test your implementation with the following:
1 int main() {
2 int test[] = {1,2,3,4,5};
3 LinkList l1(test+1,4), l2(test,5);
4 LinkList l3=l2, l4;
5 l4=l1;
6 printf("%d %d %d\n",l1.pop(),l3.pop(),l4.pop());
7 return 0;
8 }
*/
#include <iostream>

struct tree { int val; struct tree *left; struct tree *right; };

class LinkList {
    int value;
    LinkList* next;
    public: 
    LinkList(int value = -1 , LinkList* next = nullptr): value(value), next(next) {};
    ~LinkList() {
        LinkList* current = this->next;
        while (current) {
            LinkList* temp = current;
            current = current->next;
            delete temp;
        }
    }


    int pop(){
        int original_value = value;
        if (next) {
        int return_value = value;
        LinkList* oldnext = next;
        value = next -> value;
        next = next -> next;
        delete oldnext;
        }
        else{
            value = -1;
        }
        return original_value;
    }
    void add(int val){
        LinkList* newNode = new LinkList(value,next);
        value = val;
        next = newNode;
    }

};


int main() {
    LinkList list; // starts as empty (-1)


    list.add(3);
    list.add(2);
    list.add(1);


    //std::cout << "Pop: " << list.pop() << std::endl;

    //std::cout << "Pop: " << list.pop() << std::endl;

    //std::cout << "Pop: " << list.pop() << std::endl;

    return 0;
}

