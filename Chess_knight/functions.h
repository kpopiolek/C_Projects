#pragma once

#define CHESSBOARD_SIZE 6
#define HORSE_MOVES 8

typedef enum {
    FIRST, SECOND, THIRD, FOURTH, FIFTH, SIXTH, SEVENTH, EIGHT
}HMoves;

typedef struct {
    int x;
    int y;
}Point;


int move( int** pChessBoard, int nDim, int move, int x, int y, int* px, int* py, Point* pHorseMoves );

int root( int** pChessBoard, int nDim, int x, int y, Point* pHorseMoves, unsigned long long* noExe );

int** createChessboard( int nDim );

void freeChessboard( int*** pChessBoard );

void printChessBoard( int** pChessBoard, int nDim );

void printRes( unsigned long long noExe );