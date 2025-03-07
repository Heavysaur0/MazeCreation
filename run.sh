#!/bin/bash
gcc main.c maze.c deque.c -o main
if [ $? -eq 0 ]; then
    ./main
else
    echo "Compilation failed!"
fi