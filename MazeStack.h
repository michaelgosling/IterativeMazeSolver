// Header for MazeStack.cpp
// Description: Fixed size stack using an array.
// Created by Michael Gosling on 1/24/19.

#ifndef ITERATIVEMAZESOLVER_MAZESTACK_H
#define ITERATIVEMAZESOLVER_MAZESTACK_H

#include "Maze.h"

struct move { int row, col; Direction direction;};

class MazeStack {
private:
    move *contents;
    int top;
    int maxSize;
public:
    MazeStack(int maxSz);
    ~MazeStack();
    void push(move);
    move pop();
    bool isEmpty() const;
    bool isFull() const;
};

#endif //ITERATIVEMAZESOLVER_MAZESTACK_H
