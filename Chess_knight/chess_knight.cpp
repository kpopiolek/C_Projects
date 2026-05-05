
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include "functions.h"


int main( int argc, char* argv[] )
{
    if( argc != 3 )
    {
        printf( "Invalid number of arguments! Correct: <name_file> <x0> <y0>\n" );
        return 2;
    }
    int x0 = atoi( argv[ 1 ] );
    int y0 = atoi( argv[ 2 ] );

    if( x0 < 0 || x0 >= CHESSBOARD_SIZE || y0 < 0 || y0 >= CHESSBOARD_SIZE )
        return 3;

    unsigned long long noExe = 0;

    int** pChessBoard = createChessboard( CHESSBOARD_SIZE );
    Point HorseMove[ HORSE_MOVES ] = { {-2,1}, {2,1}, {2,-1}, {-2,-1}, {1,2}, {1,-2}, {-1,2}, {-1,-2} };

    int result = root( pChessBoard, CHESSBOARD_SIZE, x0, y0, HorseMove, &noExe );
    if( !result )
        printf( "It's impossible to visit all squares once!\n\n" );
    else
        printChessBoard( pChessBoard, CHESSBOARD_SIZE );

    freeChessboard( &pChessBoard );
    printRes( noExe );
    return 0;
}

