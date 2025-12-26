#include <iostream>

class LinkList {
    int value;
    LinkList* next;
public:
    LinkList(int value = -1, LinkList* next = nullptr)
        : value(value), next(next) {}

    ~LinkList() {
        LinkList* current = this->next;
        while (current) {
            LinkList* temp = current;
            current = current->next;
            delete temp;
        }
    }

    int pop() {
        int original_value = value;
        if (next) {
            LinkList* oldnext = next;
            value = next->value;
            next = next->next;
            delete oldnext;
        } else {
            value = -1;
        }
        return original_value;
    }

    void add(int val) {
        LinkList* newNode = new LinkList(value, next);
        value = val;
        next = newNode;
    }

    void print() const {
        const LinkList* current = this;
        while (current && current->value != -1) {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkList list;

    list.add(3);
    list.add(2);
    list.add(1);

    list.print(); // Output: 1 2 3

    std::cout << "Pop: " << list.pop() << std::endl;
    list.print(); // Output: 2 3

    std::cout << "Pop: " << list.pop() << std::endl;
    list.print(); // Output: 3

    std::cout << "Pop: " << list.pop() << std::endl;
    list.print(); // Output: (empty)

    return 0;
}
