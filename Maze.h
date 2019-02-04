// Maze.h: header file for Maze class
// Created by Michael Gosling on 1/28/19.
// Updated by Michael Gosling on 1/30/19.

#ifndef ITERATIVEMAZESOLVER_MAZE_H
#define ITERATIVEMAZESOLVER_MAZE_H

#include <string>

enum Direction {
    North, East, South, West, Initial
};

class Maze {
private:
    char** mazeArray;
    int rows;
    int columns;
public:
    Maze(std::string fileName);
    ~Maze();

    int getRows();

    int getCols();

    char getPosition(int row, int col);
    void setPosition(char symbol, int row, int col);
    void printMaze();

    void writeToFile(std::string);
};


#endif //ITERATIVEMAZESOLVER_MAZE_H
