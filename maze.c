#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "maze.h"

Maze* createEmptyMaze(int width, int height) {
    Maze* maze = malloc(sizeof(Maze));
    if (!maze) return NULL; // Check allocation
    maze->width = width;
    maze->height = height;

    maze->cells = calloc(width * height, sizeof(bool));
    if (!maze->cells) {
        free(maze);
        return NULL;
    }

    maze->verticalWalls = calloc((width - 1) * height, sizeof(bool));
    if (!maze->verticalWalls) {
        free(maze->cells);
        free(maze);
        return NULL;
    }

    maze->horizontalWalls = calloc(width * (height - 1), sizeof(bool));
    if (!maze->horizontalWalls) {
        free(maze->cells);
        free(maze->verticalWalls);
        free(maze);
        return NULL;
    }

    return maze;
}

void freeMaze(Maze* maze) {
    if (maze) {
        free(maze->cells);
        free(maze->verticalWalls);
        free(maze->horizontalWalls);
        free(maze);
    }
}

void fillMazeCells(Maze* maze) {
    for (int i = 0; i < maze->width * maze->height; i++) {
        maze->cells[i] = true;
    }
}

void filleMazeVerticalWalls(Maze* maze) {
    for (int i = 0; i < (maze->width - 1) * maze->height; i++) {
        maze->verticalWalls[i] = true;
    }
}

void fillMazeHorizontalWalls(Maze* maze) {
    for (int i = 0; i < maze->width * (maze->height - 1); i++) {
        maze->horizontalWalls[i] = true;
    }
}

void fillMaze(Maze* maze) {
    fillMazeCells(maze);
    filleMazeVerticalWalls(maze);
    fillMazeHorizontalWalls(maze);
}

void displayMaze(Maze* maze) {
    int w = maze->width;
    int h = maze->height;

    // Draw top border
    printf("+");
    for (int j = 0; j < w; j++) printf("--+");
    printf("\n");

    for (int i = 0; i < h; i++) {
        // Draw maze row with left border
        printf("|");
        for (int j = 0; j < w; j++) {
            printf(maze->cells[i * w + j] ? "##" : "  ");
            if (j < w - 1) printf(maze->verticalWalls[i * (w - 1) + j] ? "|" : " ");
        }
        printf("|\n"); // Right border

        // Draw horizontal walls
        if (i < h - 1) {
            printf("+");
            for (int j = 0; j < w; j++) {
                printf(maze->horizontalWalls[i * w + j] ? "--" : "  ");
                printf("+");
            }
            printf("\n");
        }
    }

    // Draw bottom border
    printf("+");
    for (int j = 0; j < w; j++) printf("--+");
    printf("\n");
}

bool leftWall(Maze* maze, int x, int y) {
    if (x == 0) return true;
    return maze->verticalWalls[y * (maze->width - 1) + x - 1];
}

bool rightWall(Maze* maze, int x, int y) {
    if (x == maze->width - 1) return true;
    return maze->verticalWalls[y * (maze->width - 1) + x];
}

bool topWall(Maze* maze, int x, int y) {
    if (y == 0) return true;
    return maze->horizontalWalls[(y - 1) * maze->width + x];
}

bool bottomWall(Maze* maze, int x, int y) {
    if (y == maze->height - 1) return true;
    return maze->horizontalWalls[y * maze->width + y];
}