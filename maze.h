#ifndef MAZE_H
#define MAZE_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int width;
    int height;
    bool* cells; // width * height
    bool* verticalWalls; // (width - 1) * height
    bool* horizontalWalls; // width * (height - 1)
} Maze;

Maze* createEmptyMaze(int width, int height);
void freeMaze(Maze* maze);

void fillMazeCells(Maze* maze);
void filleMazeVerticalWalls(Maze* maze);
void fillMazeHorizontalWalls(Maze* maze);
void fillMaze(Maze* maze);

bool leftWall(Maze* maze, int x, int y);
bool rightWall(Maze* maze, int x, int y);
bool topWall(Maze* maze, int x, int y);
bool bottomWall(Maze* maze, int x, int y);

void displayMaze(Maze* maze);


#endif