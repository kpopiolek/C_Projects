# Knight's tour problem - backtracking algorithm

## Technicalities
Language: C

Concepts: Recursion, pointers, memory managment, multi-file architecture

Contains: The folder contains of 3 files. 
  1. chess_knight.cpp - main file
  2. functions.h - headers for functions
  3. functions.cpp - implementation of functions

## Features
A procedural C implementation of a classic knight's tour problem.

The program uses backtracking method to find a solution on a chessboard of size n. Because of the used method it's recomended to try it on maximum of `7` dimensions.

The memory is being allocated dynamicly as a 2D array (using double and triple pointers) to allow flexible grid sizing and efficent memory usage.

The program includes a recursion counter that accurately tracks the number of function calls required to find a solution.

Features a bespoke, dependency-free number formatting function to display millions of recursion steps with clean, readable spaces (e.g., `10 409 208`).

## How to run
The program takes the starting coordinates of the knight (`x0`, `y0`), both in range [0, n], where n is a size of the chessboard, directly from the command line arguments.
1. Compile the code using any standard C++ compiler (MSVC, GCC, Clang)
2. Run the executable from the terminal:
  ```bash
   ./chess_knight.exe <start_x> <start_y>
Example: ./chess_knight.exe 0 0 (Starts the knight in the top-left corner).
