#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include "questions.h"
#include "lifelines.h"
#include "functions.h"

#define NUM_QUESTIONS 12

void millionaire()
{
    int sum_won = 0;
    int num_games = 0;
    char decision_play_again;

    greetings();

    //prevention of duplicate questions
    int is_used_easy[ NUM_EASY ] = { 0 };
    int is_used_medium[ NUM_MEDIUM ] = { 0 };
    int is_used_hard[ NUM_HARD ] = { 0 };
    int num_easy_used = 0;
    int num_medium_used = 0;
    int num_hard_used = 0;

    do
    {
        int is_used_5050 = 0;
        const int time_multiplier = 1;
        int is_used_friend = 0;
        int is_used_audience = 0;

		//random question selection (with prevention of duplicates)
        int w = 0;
        for( int i = 0; i < NUM_QUESTIONS; i++ )
        {
            Question p;
            if( i < 2 )
            {
                if( num_easy_used == NUM_EASY )
                {
                    num_easy_used = 0;
                    for( int j = 0; j < NUM_EASY; j++ )
                        is_used_easy[ j ] = 0;
                }
                while( 1 )
                {
                    int r = rand() % NUM_EASY;
                    if( !is_used_easy[ r ] )
                    {
                        is_used_easy[ r ] = 1;
                        num_easy_used++;
                        p = easy[ r ];
                        break;
                    }
                }
            }
            else if( i < 7 )
            {
                if( num_medium_used == NUM_MEDIUM )
                {
                    num_medium_used = 0;
                    for( int j = 0; j < NUM_MEDIUM; j++ )
                        is_used_medium[ j ] = 0;
                }
                while( 1 )
                {
                    int r = rand() % NUM_MEDIUM;
                    if( !is_used_medium[ r ] )
                    {
                        is_used_medium[ r ] = 1;
                        num_medium_used++;
                        p = medium[ r ];
                        break;
                    }
                }
            }
            else
            {
                if( num_hard_used == NUM_HARD )
                {
                    num_hard_used = 0;
                    for( int j = 0; j < NUM_HARD; j++ )
                        is_used_hard[ j ] = 0;
                }
                while( 1 )
                {
                    int r = rand() % NUM_HARD;
                    if( !is_used_hard[ r ] )
                    {
                        is_used_hard[ r ] = 1;
                        num_hard_used++;
                        p = hard[ r ];
                        break;
                    }
                }
            }

            print_q( p, w, i, is_used_5050, is_used_audience, is_used_friend, time_multiplier );

            char c;
            int is_resigning = 0;
            while( 1 )
            {
                if( scanf( " %c", &c ) != 1 )
                {
                    clean_buffer();
                    continue;
                }
                clean_buffer();

                if( c >= 'A' && c <= 'D' )
                    break;
                else if( c >= 'a' && c <= 'd' )
                {
                    c -= 32;
                    break;
                }
                else if( c == '1' )
                {
                    if( is_used_5050 )
                    {
                        color( 12 );
                        printf( "Unfortunately this lifeline is already used!\n" );
                        color( 14 );
                        printf( "Enter your answer:\n" );
                        continue;
                    }

                    printf( "Do you really want to use the 50/50 lifeline?\nPress 'Y' to confirm or 'N' to return to the question:\n" );
                    char temp;
                    while( 1 )
                    {
                        if(scanf( " %c", &temp ) != 1 )
                        {
                            clean_buffer();
                            continue;
                        }
                        clean_buffer();

                        if( temp == 'Y' || temp == 'y' )
                        {
                            is_used_5050 = 1;
                            const int time_multiplier_5050 = 0;

                            fifty_fifty( p );

                            system( "cls" );

							// Printing the question again, but with removed answers and without lifeline options
                            print_q( p, w, i, is_used_5050, is_used_audience, is_used_friend, time_multiplier_5050 );

                            break; 
                        }
                        else if( temp == 'N' || temp == 'n' )
                        {
                            printf( "We're back to the game: " );
                            break;
                        }
                        else if( temp != 'Y' && temp != 'y' && temp != 'N' && temp != 'n' )
                            printf( "Enter 'Y' or 'N'!" );
                    }
                }
                else if( c == '2' ) 
                {
                    if( is_used_audience )
                    {
                        color( 12 );
                        printf( "Unfortunately this lifeline is already used!\n" );
                        color( 14 );
                        printf( "Enter your answer:\n" );
                        continue;
                    }
                    printf( "Do you really want to use the audience lifeline?\nPress 'Y' to confirm or 'N' to return to the question:\n" );
                    char temp;
                    while( 1 )
                    {
                        if(scanf( " %c", &temp ) != 1 )
                        {
                            clean_buffer();
                            continue;
                        }
                        clean_buffer();
                        if( temp == 'Y' || temp == 'y' )
                        {
                            is_used_audience = 1;
                            audience( p.correct, i, p );
                            break;
                        }
                        else if( temp == 'N' || temp == 'n' )
                        {
                            printf( "We're back to the game: " );
                            break;
                        }
                        else if( temp != 'Y' && temp != 'y' && temp != 'N' && temp != 'n' )
                            printf( "Enter 'Y' or 'N'!" );
                    }
                }
                else if( c == '3' ) 
                {
                    if( is_used_friend )
                    {
                        color( 12 );
                        printf( "Unfortunately this lifeline is already used!\n" );
                        color( 14 );
                        printf( "Enter your answer:\n" );
                        continue;
                    }
                    printf( "Do you really want to use the friend lifeline?\nPress 'Y' to confirm or 'N' to return to the question:\n" );
                    char temp;
                    while( 1 )
                    {
                        if(scanf( " %c", &temp ) != 1 )
                        {
                            clean_buffer();
                            continue;
                        }
                        clean_buffer();
                        if( temp == 'Y' || temp == 'y' )
                        {
                            is_used_friend = 1;
                            phone( p.correct, i, p );
                            color( 14 );
                            printf( "\nThe call has ended. What is your final decision?\n" );
                            break;
                        }
                        else if( temp == 'N' || temp == 'n' )
                        {
                            printf( "We're back to the game: " );
                            break;
                        }
                        else if( temp != 'Y' && temp != 'y' && temp != 'N' && temp != 'n' )
                            printf( "Enter 'Y' or 'N'!" );
                    }
                }
                else if( c == 'P' || c == 'p' )
                {
                    printf( "Do you really want to quit the game and leave with your current prize of %d$?\n", rewards[ w ] );
                    printf( "Enter 'Y' to quit or 'N' to continue playing: " );
                    char temp;
                    while( 1 )
                    {
                        if(scanf( " %c", &temp ) != 1 )
                        {
                            clean_buffer();
                            continue;
                        }
                        clean_buffer();
                        if( temp == 'Y' || temp == 'y' )
                        {
                            is_resigning = 1;
                            break;
                        }
                        else if( temp == 'N' || temp == 'n' )
                        {
                            printf( "We're back to the game! Enter your answer: " );
                            break;
                        }
                        else if( temp != 'Y' && temp != 'y' && temp != 'N' && temp != 'n' )
                            printf( "Enter 'Y' or 'N'!" );
                    }
                    if( is_resigning )
                    {
                        printf( "Congratulations! You won %d$\n", rewards[ w ] );
                        break;
                    }
                }
                else
                    printf( "Answer out of range, please enter another!\n" );
            }

            if( is_resigning )
            {
                sum_won += rewards[ w ];
                num_games++;
                break;
            }

            Sleep( 1000 );
\
            check_answer();
            Sleep( 3000 );
            if( c == p.correct )
            {
                w++;
                if( w < 12 )
                {
                    color( 10 );
                    printf( "Congratulations! You won %d%!\n\n", rewards[ w ] );
                    Sleep( 3000 );
                }
            }
            else
            {
                defeat( i, p );
                sum_won += rewards[ win( w ) ];
                num_games++;
                break;
            }
        }

        if( w == 12 )
        {
            color( 10 );
            printf( "\nLADIES AND GENTLEMEN WE'VE GOT A WINNER! GOOD JOB! YOU WON THE GRAND PRIZE!\n" );
            sum_won += rewards[ 12 ];
            num_games++;
        }

        color( 9 );
        printf( "\n-----------------------------------\n" );
        printf( "Do you want to play again? (Y/N): " );

        while( 1 ) 
        {
            if(scanf( " %c", &decision_play_again ) != 1 )
            {
                clean_buffer();
                continue;
            }
            clean_buffer();

            if( decision_play_again == 'y' || decision_play_again == 'Y' ) {
                break;
            }
            else if( decision_play_again == 'n' || decision_play_again == 'N' ) {
                break;
            }
            else {
                printf( "Enter 'Y' or 'N': " );
            }
        }
    } while( decision_play_again == 'Y' || decision_play_again == 'y' );

    goodbye( sum_won, num_games );
}