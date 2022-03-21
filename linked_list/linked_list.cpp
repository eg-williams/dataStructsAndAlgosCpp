#include "linked_list.h"
#include <iostream>
l_list::l_list() {
}

// Clear down the linked list to nothing.
l_list::~l_list() {
    while(head) {
        // std::cout << head->data << "\n";
        head = std::move(head->next);
    }
}

void l_list::push(int data) {
    head = std::unique_ptr<Node>(new Node{data, std::move(head)});
}

void l_list::pop() {
    if(head == nullptr) {
        return;
    } 
    std::unique_ptr<Node> temp = std::move(head);
    head = std::move(temp->next);
}

/*
 * Would be nice to be able to print the list in a nice fashion.
 */
std::ostream& operator<<(std::ostream &os, const l_list &list) {
    l_list::Node *head = list.head.get();
    while(head) {
        os << head->data << ' ';
        head = head->next.get();
    }
    return os;
}

int main() {
    l_list test;
    for(int i = 0; i < 10; ++i) {
        test.push(i);
    }
    std::cout << test << "\n";
    test.pop();
    test.pop();
    std::cout << test << "\n";
}