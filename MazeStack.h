// Header for MazeStack.cpp
// Description: Fixed size stack using an array.
// Created by Michael Gosling on 1/24/19.

#ifndef ITERATIVEMAZESOLVER_MAZESTACK_H
#define ITERATIVEMAZESOLVER_MAZESTACK_H

#include "Maze.h"

struct Move {
    int row, col;
    Direction direction, backwards;
};

class MazeStack {
private:
    Move *contents;
    int top;
    int maxSize;
public:
    MazeStack(int maxSz);
    ~MazeStack();

    void push(Move);

    Move pop();
    bool isEmpty() const;
    bool isFull() const;
};

#endif //ITERATIVEMAZESOLVER_MAZESTACK_H
