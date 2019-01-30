// Maze.cpp: source file for Maze class
// Created by Michael Gosling on 1/28/19.
// Updated by Michael Gosling on 1/30/19.

#include "Maze.h"
#include <iostream>
#include <fstream>

Maze::Maze(std::string fileName) {
    std::ifstream file;
    std::string line;
    int rows = 0;
    // try to read the maze file
    try {
        file.open("filename");
        if (file.is_open()){
            while(getline(file,line)){
                rows++;
            }
            file.clear();
            file.seekg(0, std::ios::beg);
            line = "";
            mazeArray = new char*[rows];
            int row = 0;
            while(getline(file, line)) {
                char* lineArr = new char[line.size()];
                for (unsigned long i = 0; i < line.size()-1; i++)
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

}

int Maze::getNumColumns() {
    return 0;
}

int Maze::getNumRows() {
    return 0;
}

char Maze::getPosition() {
    return 0;
}

void Maze::setPosition(char) {

}

void Maze::printMaze() {

}
