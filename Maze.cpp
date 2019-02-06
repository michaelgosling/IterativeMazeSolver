// Maze.cpp: source file for Maze class
// Created by Michael Gosling on 1/28/19.
// Updated by Michael Gosling on 1/30/19.

#include "Maze.h"
#include <iostream>
#include <fstream>
#include <cstring>

Maze::Maze(std::string fileName) {
    std::ifstream file;
    std::string line;
    rows = 0;
    columns = 0;
    // try to read the maze file
    try {
        file.open(fileName);
        if (file.is_open()){
            while(getline(file,line)){
                if (columns == 0) {
                    bool lastColumnFound = false;
                    int i = (int) line.size();
                    while (!lastColumnFound) {
                        i--;
                        if (line[i] == '+')
                            lastColumnFound = true;
                    }
                    columns = i + 1;
                }
                rows++;
            }
            file.clear();
            file.seekg(0, std::ios::beg);
            line = "";
            mazeArray = new char*[rows];
            int row = 0;
            while(getline(file, line)) {
                char *lineArr = new char[columns];
                for (unsigned long i = 0; i < columns; i++)
                    lineArr[i] = line[i];

                mazeArray[row] = lineArr;
                row++;
            }
            file.close();
        } else
            std::cout << "Couldn't open file" << std::endl;
    } catch (std::exception e) {
        std::cout << e.what() << std::endl;
    }
}

Maze::~Maze() {
    for (auto i = columns; i >= 0; i--)
        mazeArray[i] = nullptr;
    mazeArray = nullptr;
}

int Maze::getRows() { return rows; }

int Maze::getCols() { return columns; }

char Maze::getPosition(int row, int col) {
    return mazeArray[row][col];
}

void Maze::setPosition(char symbol, int row, int col) {
    mazeArray[row][col] = symbol;
}

void Maze::printMaze() {
    for (auto i = 0; i < rows; i++)
        std::cout << mazeArray[i] << std::endl;
}

void Maze::writeToFile(std::string fileName) {
    std::ofstream file;
    std::string line;
    try {
        file.open(fileName);
        if (file.is_open()) {
            for (auto i = 0; i < rows; i++)
                file << mazeArray[i] << std::endl;
            file.close();
        }
    } catch (std::exception e) {
        std::cout << e.what() << std::endl;
    }
}
