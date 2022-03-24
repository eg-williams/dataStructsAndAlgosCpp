#pragma once
/**
 * @brief Will start as a stack of integers. But will try
 * and make it a template at some point. 
 */

template<class T, std::size_t NUM_ELEM>
class myStack {

public:
    myStack();
    T pop();
    void push(T const &);
    void printStack();
    bool isEmpty();
    bool isFull();
    void clearStack();

private:
    int front;
    T stck[NUM_ELEM];
};
