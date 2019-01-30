// Header for MazeStack.cpp
// Description: Fixed size stack using an array.
// Created by Michael Gosling on 1/24/19.

#ifndef ITERATIVEMAZESOLVER_MAZESTACK_H
#define ITERATIVEMAZESOLVER_MAZESTACK_H

struct Position { int row, col; };

class MazeStack {
private:
    Position *contents;
    int top;
    int maxSize;
public:
    MazeStack(int maxSz);
    ~MazeStack();
    void push(Position);
    Position pop();
    bool isEmpty() const;
    bool isFull() const;
};

#endif //ITERATIVEMAZESOLVER_MAZESTACK_H
