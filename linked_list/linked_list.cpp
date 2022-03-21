#include "linked_list.h"
#include <iostream>
l_list::l_list() {
}

// Clear down the linked list to nothing.
l_list::~l_list() {
    while(head) {
        std::cout << head->data << "\n";
        head = std::move(head->next);
    }
}

void l_list::push(int data) {
    head = std::unique_ptr<Node>(new Node{data, std::move(head)});
}

int main() {
    l_list test;
    for(int i = 0; i < 10; ++i) {
        test.push(i);
    }
}