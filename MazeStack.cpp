//
// Created by mgosling94 on 1/24/19.
//

#include <iostream>
#include "MazeStack.h"

/**
 * Constructor
 * @param maxSz Integer representing Max Size of the stack
 */
MazeStack::MazeStack(int maxSz) {
    // Allocate new array to hold contents
    contents = new Move[maxSz];

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
MazeStack::~MazeStack() {
    // delete array
    delete [] contents;
    contents = nullptr;
    maxSize = 0; // set max size to 0
    top = -1; // empty
}

/**
 * Push a position to the stack
 * @param move Position
 */
void MazeStack::push(Move move) {
    // is stack full? show error and exit
    if (isFull()) {
        std::cout << "Can't push Move on stack: stack is full.\n";
        exit(1);
    }

    // put info in array, update top
    contents[++top] = move;
}

/**
 * Take a position off the top of the stack and return it
 * @return Position
 */
Move MazeStack::pop() {
    // if the stack is empty, display error and exit
    if (isEmpty()){
        std::cout << "Can't pop position from stack: stack is empty\n";
        exit(1);
    }
    return contents[top--];
}

/**
 * Check if stack is empty
 * @return boolean
 */
bool MazeStack::isEmpty() const {
    // if top is less than 0, we know it's empty
    return top < 0;
}

/**
 * Check if stack is full
 * @return boolean
 */
bool MazeStack::isFull() const {
    // top is an index so if it's equal to maxSize -1 then the stack is full
    return top == maxSize -1;
}
