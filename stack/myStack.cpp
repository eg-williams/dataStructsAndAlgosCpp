#include <iostream>
// So for some reason if this include is above the system include
// the compiler really doesn't like it....
#include "myStack.hpp"

template<class T, std::size_t N>
myStack<T, N>::myStack() {      
    front = -1;
    // Blat the stack first...
    for(int i = 0; i < N; i++) {        
        stck[i] = 0;
    }
    
}
template<typename T, std::size_t N>
void myStack<T, N>::clearStack() {
    for(int i = 0; i < N; i++) {        
        stck[i] = 0;
    }
}

template<typename T, std::size_t N>
void myStack<T, N>::push(T const & val) {    
    if(isFull()) {
        std::cout << "Stack Overflow\n";
        return;
    }
    ++front;
    stck[front] = val;    
}

template<typename T, std::size_t N>
T myStack<T, N>::pop() {
    int temp;
    if(isEmpty()) {
        return 0;
    } 
    temp = stck[front];
    stck[front] = 0; 
    --front;
    return temp;
}
template<typename T, std::size_t N>
bool myStack<T, N>::isFull() {
    if(front == (N -1)) {
        return true;
    }
    return false;
}

template<typename T, std::size_t N>
bool myStack<T, N>::isEmpty() {
    if(front == -1) {
        return true;
    } 
    return false;
}

template<typename T, std::size_t N>
void myStack<T, N>::printStack() {
    for(int i = 0; i < front + 1; ++i) {
        std::cout << i << ", " << stck[i] << "\n";
    }
}

int main() {
    myStack<int, 10> stack {};
    
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);
    stack.push(60);
    stack.push(70);
    stack.push(80);
    stack.push(90);
    stack.push(100);    
    stack.printStack();

    std::cout << "element popped is " << stack.pop() << "\n";
    std::cout << "element popped is " << stack.pop() << "\n";
    std::cout << "element popped is " << stack.pop() << "\n";
    stack.printStack();
}

