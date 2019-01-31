#include <iostream>
#include "MazeStack.h"
#include "Maze.h"

int main() {
    Maze maze("./mazes/maze.txt");
    MazeStack stack(maze.getRows());
    unsigned int currentRow = 0;
    unsigned int currentCol = 0;

    for (unsigned int i = 0; i < maze.getRows(); i++)
        if (maze.getPosition(i, 0) == ' ')
            currentRow = i;

    maze.setPosition('#', currentRow, currentCol);
    maze.printMaze();

    // check for possible directions
    bool directions[4] = {false, false, false, false}; // 0-3 up down left right

    if (currentRow-1 >= 0 && maze.getPosition(currentRow-1, currentCol) == ' ')
        directions[0] = true;
    if (currentCol+1 <= maze.getCols()-1 && maze.getPosition(currentRow, currentCol+1) == ' ')
        directions[1] = true;
    if (currentRow+1 <= maze.getRows()-1 && maze.getPosition(currentRow+1, currentCol) == ' ')
        directions[2] = true;
    if (currentCol-1 >= 0 && maze.getPosition(currentRow, currentCol-1) == ' ')
        directions[3] = true;

    // TODO: go possible direction and put move on the stack

    return 0;
}