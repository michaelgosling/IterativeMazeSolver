#include <iostream>
#include "MazeStack.h"

int main() {
    Maze maze("./mazes/maze.txt");
    MazeStack stack(maze.getRows() * maze.getCols());
    int currentRow = 0;
    int currentCol = 0;
    Direction previousPosition = Initial;
    bool mazeSolved = false;
    int endRow = 0;

    // get starting row
    for (unsigned int i = 0; i < maze.getRows(); i++)
        if (maze.getPosition(i, 0) == ' ')
            currentRow = i;

    // get ending row
    for (unsigned int i = 0; i < maze.getRows(); i++)
        if (maze.getPosition(i, maze.getCols() - 1) == ' ')
            endRow = i;

    // set starting position
    maze.setPosition('#', currentRow, currentCol);

    // loop until maze is solved
    while (!mazeSolved) {
        // check for possible directions
        bool directions[4] = {false, false, false, false}; // 0-3 up down left right

        if (currentRow - 1 >= 0 && maze.getPosition(currentRow - 1, currentCol) == ' ' && previousPosition != North)
            directions[0] = true;
        if (currentCol + 1 <= maze.getCols() - 1 && maze.getPosition(currentRow, currentCol + 1) == ' ' &&
            previousPosition != East)
            directions[1] = true;
        if (currentRow + 1 <= maze.getRows() - 1 && maze.getPosition(currentRow + 1, currentCol) == ' ' &&
            previousPosition != South)
            directions[2] = true;
        if (currentCol - 1 >= 0 && maze.getPosition(currentRow, currentCol - 1) == ' ' && previousPosition != West)
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
            if (currentRow == endRow && currentCol == maze.getCols() - 1)
                mazeSolved = true;
            else {
                // if we haven't, go back to last time we made a turn and set a flag
                Move lastTurn = stack.pop();
                switch (lastTurn.direction) {
                    case North:
                        maze.setPosition('N', lastTurn.row - 1, lastTurn.col);
                        break;
                    case East:
                        maze.setPosition('N', lastTurn.row, lastTurn.col + 1);
                        break;
                    case South:
                        maze.setPosition('N', lastTurn.row + 1, lastTurn.col);
                        break;
                    case West:
                        maze.setPosition('N', lastTurn.row, lastTurn.col - 1);
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
            stack.push(move);
        }
        // drop a # symbol on the current position
        maze.setPosition('#', currentRow, currentCol);
    }
    // TODO: clean up wrong paths

    // print solution
    maze.printMaze();
    return 0;
}