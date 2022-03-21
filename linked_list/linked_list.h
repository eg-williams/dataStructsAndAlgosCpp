#pragma once
#include <memory>
#include <ostream>

class l_list 
{
public:
    l_list();
    ~l_list();

    struct Node {
        int data;
        std::unique_ptr<Node> next;
    };

    std::unique_ptr<Node> head;
    void push(int data);
    void pop();
};
