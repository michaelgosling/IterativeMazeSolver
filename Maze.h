// Maze.h: header file for Maze class
// Created by Michael Gosling on 1/28/19.
// Updated by Michael Gosling on 1/30/19.

#ifndef ITERATIVEMAZESOLVER_MAZE_H
#define ITERATIVEMAZESOLVER_MAZE_H

#include <string>

enum Direction {North, East, South, West};

class Maze {
private:
    char** mazeArray;
    unsigned int rows;
    unsigned int columns;
public:
    Maze(std::string fileName);
    ~Maze();

    unsigned int getRows();
    unsigned int getCols();
    char getPosition(unsigned int row, unsigned int col);
    void setPosition(char symbol, int row, int col);
    void printMaze();
};


#endif //ITERATIVEMAZESOLVER_MAZE_H
