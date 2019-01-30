// Maze.h: header file for Maze class
// Created by Michael Gosling on 1/28/19.
// Updated by Michael Gosling on 1/30/19.

#ifndef ITERATIVEMAZESOLVER_MAZE_H
#define ITERATIVEMAZESOLVER_MAZE_H

#include <string>

enum Direction {
    North, East, South, West
};

class Maze {
private:
    char** mazeArray;
public:
    Maze(std::string fileName);
    ~Maze();

    int getNumColumns();
    int getNumRows();
    char getPosition();
    void setPosition(char);
    void printMaze();
};


#endif //ITERATIVEMAZESOLVER_MAZE_H
