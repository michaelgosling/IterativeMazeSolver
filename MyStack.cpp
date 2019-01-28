//
// Created by mgosling94 on 1/24/19.
//

#include <iostream>
#include "MyStack.h"

/**
 * Constructor
 * @param maxSz Integer representing Max Size of the stack
 */
MyStack::MyStack(int maxSz) {
    // Allocate new array to hold contents
    contents = new StackElementT(maxSz);

    // if the array is empty, we dont have enough memory
    if (contents == nullptr) {
        std::cout << "Insufficient memory to init stack.\n";
        exit(1); // exit, returning error code.
    }

    // set argument to this stacks variable
    maxSize = maxSz;
    top = -1; // Empty
}

/**
 * Destructor
 */
MyStack::~MyStack() {
    // delete array
    delete [] contents;
    contents = nullptr;
    maxSize = 0; // set max size to 0
    top = -1; // empty
}

/**
 * Push an element to the stack
 * @param element StackElementT Stack Element
 */
void MyStack::push(StackElementT element) {
    // is stack full? show error and exit
    if (isFull()) {
        std::cout << "Can't push element on stack: stack is full.\n";
        exit(1);
    }

    // put info in array, update top
    contents[++top] = element;
    /* !! [DEMO NOTE] !!
     * ++top increments the value, then returns it
     * top++ would return the value, then increment it */
}

/**
 * Take an element off the top of the stack and return it
 * @return StackElementT stack element
 */
StackElementT MyStack::pop() {
    // if the stack is empty, display error and exit
    if (isEmpty()){
        std::cout << "Can't pop element from stack: stack is empty\n";
        exit(1);
    }

    /* !! [DEMO NOTE] !!
     * --top decrements the value, then returns it
     * top-- returns the value, then decrement it */
    return contents[top--];
}

/**
 * Check if stack is empty
 * @return
 */
bool MyStack::isEmpty() const {
    // if top is less than 0, we know it's empty
    return top < 0;
}

/**
 * Check if stack is full
 * @return boolean
 */
bool MyStack::isFull() const {
    // top is an index so if it's equal to maxSize -1 then the stack is full
    return top == maxSize -1;
}
