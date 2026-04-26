#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "questions.h"
#include "functions.h"
#include <string.h>

void audience( char correct, int level, Question p ) {
    int optionA = 0;
    int optionB = 0;
    int optionC = 0;
    int optionD = 0;
    int remainder = 100;
    int correct_percentage;

	//chance of the audience being correct depends on the level of the question
    if( level < 2 )
        correct_percentage = 70 + rand() % 26;
    else if( level < 5 )
        correct_percentage = 55 + rand() % 21;
    else if( level < 8 )
        correct_percentage = 40 + rand() % 16;
    else if( level < 11 )
        correct_percentage = 25 + rand() % 10;
    else
        correct_percentage = 20 + rand() % 10;

	// Prevention of incorrect percentage being above 100 
    if( correct_percentage > 100 ) correct_percentage = 100;

    remainder -= correct_percentage;
   
	// Asigning correct answer percentage
    if( correct == 'A' || correct == 'a' ) optionA = correct_percentage;
    else if( correct == 'B' || correct == 'b' ) optionB = correct_percentage;
    else if( correct == 'C' || correct == 'c' ) optionC = correct_percentage;
    else if( correct == 'D' || correct == 'd' ) optionD = correct_percentage;

	// Distributing the remaining percentage among the incorrect answers (but only among those that are not empty due to 50/50)
    for( int k = 0; k < remainder; k++ )
    {
        int r = rand() % 4;

		// If the randomly chosen option is empty (due to 50/50), we skip it and try again
        if( r == 0 && p.ansA[ 0 ] == '\0' ) { k--; continue; }
        if( r == 1 && p.ansB[ 0 ] == '\0' ) { k--; continue; }
        if( r == 2 && p.ansC[ 0 ] == '\0' ) { k--; continue; }
        if( r == 3 && p.ansD[ 0 ] == '\0' ) { k--; continue; }

        // If the answer exists, we add a vote
        if( r == 0 ) optionA++;
        else if( r == 1 ) optionB++;
        else if( r == 2 ) optionC++;
        else if( r == 3 ) optionD++;
    }

    color( 8 );
    printf( "Please vote for the answer you think is correct.\n" );
    Sleep( 1500 );
    printf( "Calculating votes. Please wait.\n" );
    Sleep( 3000 );
    switch( rand() % 4 )
    {
        case 0: printf( "This is the result of a vote:\n\n" ); break;
        case 1: printf( "The audience has decided. Let's see:\n\n" ); break;
        case 2: printf( "We already have the results, let's take a look:\n\n" ); break;
        case 3: printf( "Let's see what the audience thinks:\n\n" ); break;
    }
    Sleep( 1000 );

	// Printing the results in a visually appealing way, with bars representing the percentage of votes for each option. 
    color( 14 );

    printf( "A " );
    color( 14 * 16 + 14 );
    Sleep( 1000 );
    for( int l = 0; l < optionA / 2; l++ )
        printf( " " );
    color( 14 );
    printf( " (%d%%)\n", optionA );
    Sleep( 1000 );

    printf( "\nB " );
    color( 14 * 16 + 14 );
    Sleep( 1000 );
    for( int l = 0; l < optionB / 2; l++ )
        printf( " " );
    color( 14 );
    printf( " (%d%%)\n", optionB );
    Sleep( 1000 );

    printf( "\nC " );
    color( 14 * 16 + 14 );
    Sleep( 1000 );
    for( int l = 0; l < optionC / 2; l++ )
        printf( " " );
    color( 14 );
    printf( " (%d%%)\n", optionC );
    Sleep( 1000 );

    printf( "\nD " );
    color( 14 * 16 + 14 );
    Sleep( 1000 );
    for( int l = 0; l < optionD / 2; l++ )
        printf( " " );
    color( 14 );
    printf( " (%d%%)\n", optionD );
    Sleep( 1000 );

    printf( "\nThe audience has expressed their opinion. Do you trust them? Your intuition? Or will you use another lifeline?\n" );
}

void phone( char correct, int level, Question p ) {
    int who_answers = rand() % 100;
    int correct_percentage;
    int person_id;
    if( who_answers < 10 ) 
    {
        correct_percentage = 95; //expert
        person_id = 1;
    }
    else if( who_answers < 35 ) //grandma
    {
        correct_percentage = 80;
        person_id = 2;
    }
    else if( who_answers < 75 ) //friend
    {
        correct_percentage = 50;
        person_id = 3;
    }
    else if( who_answers < 95 ) //aunt
    {
        correct_percentage = 30;
        person_id = 4;
    }
    else //uncle
    {
        correct_percentage = 10;
        person_id = 5;
    }

    //generating the answer 
    char ans;
    if( rand() % 100 <= correct_percentage )
    {
        ans = correct;
    }
    else
    {
		// If the answer is unavailable due to 50/50, we need to randomly select an answer from the remaining options.
        while( 1 )
        {
            int r = rand() % 4;
            // Sprawdzamy czy wylosowana odpowiedz istnieje (nie jest pusta)
            if( r == 0 && p.ansA[ 0 ] != '\0' ) { ans = 'A'; break; }
            if( r == 1 && p.ansB[ 0 ] != '\0' ) { ans = 'B'; break; }
            if( r == 2 && p.ansC[ 0 ] != '\0' ) { ans = 'C'; break; }
            if( r == 3 && p.ansD[ 0 ] != '\0' ) { ans = 'D'; break; }
        }
    }

    color( 8 );
    if( person_id == 1 )
    {
        printf( "[Host] Good evening! Here's the host of a TV show Who Wants to Be a Millionaire!\n" );
        Sleep( 1000 );
        printf( "[Expert] Good evening, Mr. Host. In what can I be of service?\n" );
        Sleep( 1000 );
        printf( "[Host] We need your expertise. Do you know the answer to this question?\n" );
        Sleep( 1500 );
        printf( "[Expert] Hmm..." );
        Sleep( 1500 );
        printf( "[Expert] " );
        switch( rand() % 4 )
        {
            case 0: printf( "I'm sure it's %c", ans ); break;
            case 1: printf( "Without two words, it will be %c", ans ); break;
            case 2: printf( "I don't have doubts. It must be %c", ans ); break;
            case 3: printf( "It's definitely %c", ans ); break;
        }
    }
    else if( person_id == 2 )
    {
        printf( "[Host] Good evening! Here's Host from the show Millionaire. Are you talking to Grandma Janina?\n" );
        Sleep( 1000 );
        printf( "[Grandma Janina] Oh no! Grandchild! Is that you? Have you had dinner today?\n" );
        Sleep( 1000 );
        printf( "[Host] Mrs. Janina, your grandchild is playing for a big prize. He needs your help.\n" );
        Sleep( 1500 );
        printf( "[Grandma Janina] I'm looking for my glasses... they were somewhere... I've got them.\n" );
        Sleep( 1500 );
        printf( "[Grandma Janina] " );
        switch( rand() % 4 )
        {
            case 0: printf( "I think it will be %c, darling.\n", ans ); break;
            case 1: printf( "Grandma's heart says %c.\n", ans ); break;
            case 2: printf( "I have once heard about it in Radio Maryja. It's %c.\n", ans ); break;
            case 3: printf( "Pick %c, but if it's wrong, don't blame Grandma.\n", ans ); break;
        }
    }
    else if( person_id == 3 ) 
    {
        printf( "[Host] Welcome to the show. Your friend needs help.\n" );
        Sleep( 1000 );
        printf( "[Friend] Hi! How are you? Are you really on TV?\n" );
        Sleep( 1000 );
        printf( "[Host] Let's focus. Time is running out. Do you know the answer?\n" );
        Sleep( 1500 );
        printf( "[Friend] Damn, man... this is tough.\n" );
        Sleep( 1500 );
        printf( "[Friend] " );
        switch( rand() % 4 )
        {
            case 0: printf( "I'm not sure, but I'd bet on %c.\n", ans ); break;
            case 1: printf( "I remember something about it from school. It's probably %c.\n", ans ); break;
            case 2: printf( "Something tells me it's %c. Take a risk.\n", ans ); break;
            case 3: printf( "I'm going to go with %c, but don't blame me if I'm wrong!\n", ans ); break;
        }
    }
    else if( person_id == 4 ) 
    {
        printf( "[Host] Hello? It's the Host.\n" );
        Sleep( 1000 );
        printf( "[Aunt Grazyna] O mother! Host! Wiesiek, come quickly, Host is calling!\n" );
        Sleep( 1000 );
        printf( "[Host] Dear Grazyno, please be quiet. What is the correct answer?\n" );
        Sleep( 1500 );
        printf( "[Aunt Grazyna] Let me think...!\n" );
        Sleep( 1500 );
        printf( "[Aunt Grazyna] " );
        switch( rand() % 4 )
        {
            case 0: printf( "I read about it in 'Pani Domu'. It's %c!\n", ans ); break;
            case 1: printf( "Uncle Wiesiek shouts, it's %c, and he knows!\n", ans ); break;
            case 2: printf( "One hundred percent %c! Trust your aunt!\n", ans ); break;
            case 3: printf( "It must be %c, there's no other option!\n", ans ); break;
        }
    }
    else 
    {
        printf( "[Host] Hello? It's the Host.\n" );
        Sleep( 1000 );
        printf( "[Uncle Janusz] Good evening! When will you give back my drill?\n" );
        Sleep( 1000 );
        printf( "[Host] Dear Mr. Janusz, this question is worth a lot of money. Please be patient.\n" );
        Sleep( 1500 );
        printf( "[Uncle Janusz] Man, what is this question? For kindergarteners?\n" );
        Sleep( 1500 );
        printf( "[Uncle Janusz] " );
        switch( rand() % 4 )
        {
            case 0: printf( "Easy! Take %c and you'll win the money!\n", ans ); break;
            case 1: printf( "Hahaha! %c! Everybody knows it!\n", ans ); break;
            case 2: printf( "Don't even read further. It's %c.\n", ans ); break;
            case 3: printf( "Of course, it's %c. If you lose, don't come back home!\n", ans ); break;
        }
    }
}

void fifty_fifty( Question& p )
{
    // Randomizing the WRONG answer to keep along with the correct one
    int temp = rand() % 3;

	// check witch answer is correct and remove two wrong answers, leaving the one randomized by 'los' and the correct one
    if( p.correct == 'A' || p.correct == 'a' ) // A is correct 
    {
        if( temp == 0 )      
        {
            strcpy( p.ansC, "" );
            strcpy( p.ansD, "" );
        }
        else if( temp == 1 ) 
        {
            strcpy( p.ansB, "" );
            strcpy( p.ansD, "" );
        }
        else               
        {
            strcpy( p.ansB, "" );
            strcpy( p.ansC, "" );
        }
    }
    else if( p.correct == 'B' || p.correct == 'b' ) // B is correct
    {
        if( temp == 0 )      // keep A
        {
            strcpy( p.ansC, "" );
            strcpy( p.ansD, "" );
        }
        else if( temp == 1 ) // keep C
        {
            strcpy( p.ansA, "" );
            strcpy( p.ansD, "" );
        }
        else               // keep D
        {
            strcpy( p.ansA, "" );
            strcpy( p.ansC, "" );
        }
    }
	else if( p.correct == 'C' || p.correct == 'c' ) //C is correct
    {
        
        if( temp == 0 )      // keep A
        {
            strcpy( p.ansB, "" );
            strcpy( p.ansD, "" );
        }
        else if( temp == 1 ) // keep B
        {
            strcpy( p.ansA, "" );
            strcpy( p.ansD, "" );
        }
        else               // keep D
        {
            strcpy( p.ansA, "" );
            strcpy( p.ansB, "" );
        }
    }
	else if( p.correct == 'D' || p.correct == 'd' ) // D is correct
    {
        if( temp == 0 )      // keep A
        {
            strcpy( p.ansB, "" );
            strcpy( p.ansC, "" );
        }
        else if( temp == 1 ) // keep B
        {
            strcpy( p.ansA, "" );
            strcpy( p.ansC, "" );
        }
        else               // keep C
        {
            strcpy( p.ansA, "" );
            strcpy( p.ansB, "" );
        }
    }
}
