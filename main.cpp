#include <iostream>
#include "MazeStack.h"

int currentRow, currentCol, endRow, startRow;
bool mazeSolved;
Direction previousPosition;

void move(char validPath, char charToSet, Maze *maze, MazeStack *stack) {


    // check for possible directions
    bool directions[4] = {false, false, false, false}; // 0-3 up down left right

    if (currentRow - 1 >= 0 && maze->getPosition(currentRow - 1, currentCol) == validPath && previousPosition != North)
        directions[0] = true;
    if (currentCol + 1 <= maze->getCols() - 1 && maze->getPosition(currentRow, currentCol + 1) == validPath &&
        previousPosition != East)
        directions[1] = true;
    if (currentRow + 1 <= maze->getRows() - 1 && maze->getPosition(currentRow + 1, currentCol) == validPath &&
        previousPosition != South)
        directions[2] = true;
    if (currentCol - 1 >= 0 && maze->getPosition(currentRow, currentCol - 1) == validPath && previousPosition != West)
        directions[3] = true;

    // check if there's only one possible direction, if so go that way
    auto moves = 0;
    for (bool direction : directions)
        if (direction) moves++;

    if (moves == 1) {
        // go only possible direction
        if (directions[0]) {
            // North
            currentRow--;
            previousPosition = South;
        } else if (directions[1]) {
            // East
            currentCol++;
            previousPosition = West;
        } else if (directions[2]) {
            // South
            currentRow++;
            previousPosition = North;
        } else if (directions[3]) {
            // West
            currentCol--;
            previousPosition = East;
        }
    } else if (moves == 0) {
        // if there's no possible directions, check if we've solved it
        if (currentRow == endRow && currentCol == maze->getCols() - 1)
            mazeSolved = true;
        else {
            // if we haven't, go back to last time we made a turn and set a flag
            Move lastTurn = stack->pop();
            switch (lastTurn.direction) {
                case North:
                    maze->setPosition('N', lastTurn.row - 1, lastTurn.col);
                    break;
                case East:
                    maze->setPosition('N', lastTurn.row, lastTurn.col + 1);
                    break;
                case South:
                    maze->setPosition('N', lastTurn.row + 1, lastTurn.col);
                    break;
                case West:
                    maze->setPosition('N', lastTurn.row, lastTurn.col - 1);
            }
            currentRow = lastTurn.row;
            currentCol = lastTurn.col;
            previousPosition = lastTurn.backwards;
        }
    } else {
        Move move; // move to put on stack
        move.backwards = previousPosition; // set which way is backwards for when we pop back
        if (directions[2]) {
            // try south first
            currentRow++;
            move.direction = South;
            move.col = currentCol;
            move.row = currentRow - 1;
            previousPosition = North;
        } else if (directions[1]) {
            // try east
            currentCol++;
            move.direction = East;
            move.col = currentCol - 1;
            move.row = currentRow;
            previousPosition = West;
        } else if (directions[0]) {
            // north
            currentRow--;
            move.direction = North;
            move.col = currentCol;
            move.row = currentRow + 1;
            previousPosition = South;
        } else if (directions[3]) {
            // west
            currentCol--;
            move.direction = West;
            move.col = currentCol + 1;
            move.row = currentRow;
            previousPosition = East;
        }

        // push turn move onto stack
        stack->push(move);
    }
    // drop a symbol on the current position
    maze->setPosition(charToSet, currentRow, currentCol);
}

int main() {
    Maze maze("./mazes/maze2.txt");
    MazeStack stack(maze.getRows() * maze.getCols());
    currentRow = 0;
    currentCol = 0;
    previousPosition = Initial;
    mazeSolved = false;
    endRow = 0;
    startRow = 0;

    // get starting row
    for (unsigned int i = 0; i < maze.getRows(); i++)
        if (maze.getPosition(i, 0) == ' ')
            startRow = i;

    currentRow = startRow;

    // get ending row
    for (unsigned int i = 0; i < maze.getRows(); i++)
        if (maze.getPosition(i, maze.getCols() - 1) == ' ')
            endRow = i;


    // set starting position
    maze.setPosition('O', currentRow, currentCol);

    // loop until maze is solved
    while (!mazeSolved) {
        move(' ', 'O', &maze, &stack);
    }
    // go through the maze again, setting the correct path to #
    mazeSolved = false;
    MazeStack cleanupStack(maze.getCols() * maze.getRows());
    previousPosition = Initial;
    currentCol = 0;
    currentRow = startRow;
    // set starting position
    maze.setPosition('#', currentRow, currentCol);
    while (!mazeSolved) {
        move('O', '#', &maze, &cleanupStack);
    }

    // replace every N or O with a space
    for (auto i = 0; i < maze.getRows(); i++) {
        for (auto j = 0; j < maze.getCols() - 1; j++) {
            if (maze.getPosition(i, j) == 'N' || maze.getPosition(i, j) == 'O')
                maze.setPosition(' ', i, j);
        }
    }


    // write to file
    maze.writeToFile("./mazes/MazeSolution.txt");
    return 0;
}