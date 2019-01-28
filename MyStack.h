// Header for MyStack.cpp
// Description: Fixed size stack using an array.
// Created by Michael Gosling on 1/24/19.

#ifndef STACK_MYSTACK_H
#define STACK_MYSTACK_H

typedef char StackElementT;

class MyStack {
private:
    StackElementT *contents;
    int top;
    int maxSize;
public:
    MyStack(int maxSz);
    ~MyStack();
    void push(StackElementT);
    StackElementT pop();
    bool isEmpty() const;
    bool isFull() const;

};

#endif //STACK_MYSTACK_H
