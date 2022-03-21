#include "linked_list.h"
#include <iostream>

template<typename T>
l_list<T>::l_list() {
}

// Called when the list goes out of scope.  Because
// I'm using unique_ptr, then it will get deleted as the 
// unique pointer goes out of scope.
template<typename T>
l_list<T>::~l_list() {
    while(head) {
        head = std::move(head->next);
    }
}

template<typename T>
void l_list<T>::push(const T & data) {
    head = std::unique_ptr<Node>(new Node{data, std::move(head)});
}

template<typename T>
void l_list<T>::pop() {
    if(head == nullptr) {
        return;
    } 
    std::unique_ptr<Node> temp = std::move(head);
    head = std::move(temp->next);
}

/*
 * Would be nice to be able to print the list in a nice fashion.
 */
template<typename T>
std::ostream& operator<<(std::ostream &os, const l_list<T> &list) {    
    auto *head = list.head.get();
    while(head) {
        os << head->data << ' ';
        head = head->next.get();
    }
    return os;
}

int main() {
    l_list<int> test;
    for(int i = 0; i < 10; ++i) {
        test.push(i);
    }
    std::cout << test << "\n";
    test.pop();
    test.pop();
    std::cout << test << "\n";
    l_list<std::string> names;
    names.push("Bob");
    names.push("Andrew");
    names.push("Susan");
    std::cout << names << "\n";

}