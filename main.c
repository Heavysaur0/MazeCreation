#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "maze.h"
#include "deque.h"


Maze* backtrackingMaze(int width, int height) {
    Maze* maze = createEmptyMaze(width, height);
    if (!maze) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    fillMaze(maze);
    Deque* deque = createDeque();

    


    destroyDeque(deque);
    return maze;
}


int main() {
    int width = 8, height = 5;
    Maze* maze = createEmptyMaze(width, height);
    if (!maze) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    displayMaze(maze);
    freeMaze(maze);

    return 0;
}