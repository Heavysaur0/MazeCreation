@echo off
gcc main.c maze.c deque.c -o main.exe
if %errorlevel% equ 0 (
    main.exe
) else (
    echo Compilation failed!
)
pause