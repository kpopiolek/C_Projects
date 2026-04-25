#include "functions.h"
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

int** createChessboard( int nDim )
{
    int** pTab = ( int** )calloc( nDim, sizeof( int* ) );
    if( !pTab )
        return NULL;

    int* pBlock = ( int* )calloc( nDim * nDim, sizeof( int ) );
    if( !pBlock )
    {
        free( pTab );
        return NULL;
    }

    for( int i = 0; i < nDim; i++ )
    {
        pTab[ i ] = pBlock + ( i * nDim );
    }
    return pTab;
}

void freeChessboard( int*** pChessBoard )
{
    if( !*pChessBoard )
        return;
    free( ( *pChessBoard )[ 0 ] );
    free( *pChessBoard );
    *pChessBoard = NULL;
}

void printChessBoard( int** pChessBoard, int nDim )
{
    int* p = pChessBoard[ 0 ];
    for( int i = 0; i < nDim * nDim; i++ )
    {
        printf( "%3d ", *p++ );
        if( ( 1 + i ) % nDim == 0 )
            printf( "\n" );
    }
}

int move( int** pChessBoard, int nDim, int move, int x, int y, int* px, int* py, Point* pHorseMoves )
{
    *px = x + pHorseMoves[ move ].x;
    *py = y + pHorseMoves[ move ].y;

    if( *px >= 0 && *px < nDim && *py >= 0 && *py < nDim && pChessBoard[ *px ][ *py ] == 0 )
        return 1;
    else
        return 0;
}

int root( int** pChessBoard, int nDim, int x, int y, Point* pHorseMoves, unsigned long long* noExe )
{
    static int moveNo = 1;
    pChessBoard[ x ][ y ] = moveNo;

    *noExe += 1;
    if( moveNo == nDim * nDim )
        return 1;
    else
    {
        int next_x;
        int next_y;

        for( int i = 0; i < HORSE_MOVES; i++ )
        {
            if( move( pChessBoard, nDim, i, x, y, &next_x, &next_y, pHorseMoves ) )
            {
                moveNo++;
                if( root( pChessBoard, nDim, next_x, next_y, pHorseMoves, noExe ) == 1 )
                    return 1;
                else
                    moveNo--;
            }
        }

    }
    pChessBoard[ x ][ y ] = 0;
    return 0;
}

void printRes( unsigned long long noExe )
{
    int tab[ 20 ] = { 0 };
    int i = 0;
    int noDigits = 0;
    while( noExe > 0 )
    {
        tab[ i ] = noExe % 10;
        noExe /= 10;
        i++; 
        noDigits++;
    }

    printf( "\nNumber of recursions: " );
    for( int j = noDigits-1; j >= 0; j-- )
    {
        printf( "%d", tab[ j ] );
        if( j % 3 == 0 )
            printf( " " );
    }
    printf( "\n" );
}