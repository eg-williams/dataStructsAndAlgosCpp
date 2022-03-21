#pragma once
#include <memory>
#include <ostream>

template<class T>
class l_list 
{
public:
    l_list();
    ~l_list();

    struct Node {
        T data;
        std::unique_ptr<Node> next;
    };

    std::unique_ptr<Node> head;
    void push(T const & data);
    void pop();
    void display_list();
};
