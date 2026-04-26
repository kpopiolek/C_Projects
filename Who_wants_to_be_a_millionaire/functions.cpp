#include "functions.h"
#include "questions.h"
#include <windows.h>
#include <stdio.h>
#include <conio.h>

void greetings()
{
    color( 9 );
    printf( "WELCOME TO WHO WANTS TO BE A MILLIONAIRE!\n" );
    Sleep( 5000 );
    system( "cls" );

    printf( "GAME RULES:\n" );
    printf( "1. Answer 12 questions to win the main prize.\n" );
    printf( "2. You have 4 answer options: A, B, C, D.\n" );
    printf( "3. Guaranteed levels are: 1000zl, 40000zl.\n" );
    printf( "4. At any time you can quit (key 'P').\n" );
    printf( "5. You have 3 lifelines:\n" );
    printf( "    50/50 ('1')\n" );
    printf( "    Ask the Audience ('2')\n" );
    printf( "    Phone a Friend ('3')\n" );
    printf( "Press any key to start the game...\n\n" );
    while( !_kbhit() )
        ( void )rand();
    ( void )_getch();
    system( "cls" );
}


void print_q( Question p, int w, int i, int is_5050, int is_audience, int is_phone, int time_multiplier )
{
    system( "cls" );
    color( 10 );
    printf( "Current prize: %d\n", rewards[ w ] );
    printf( "Current guaranteed prize: %d\n", rewards[ win( w ) ] );
    color( 9 );
    printf( "=============================================================================================================\n" );
    printf( "Press 'P' to quit the game with your current prize\n" );
    if( !is_5050 ) printf( "Press '1' to use 50/50 lifeline\n" );
    if( !is_audience ) printf( "Press '2' to ask the audience\n" );
    if( !is_phone ) printf( "Press '3' to call a friend\n" );
    printf( "=============================================================================================================\n" );
    Sleep( 1500 * time_multiplier );
    int temp1 = rand();
    color( 8 );
    if( !i )
    {
        switch( temp1 % 4 )
        {
            case 0: printf( "Without unnecessary delay. We are fighting for the first money. Here is the question:" ); break;
            case 1: printf( "We are starting the game for a million dollars! And here is the first question:" ); break;
            case 2: printf( "Let us hope that this will be an easy start. Here is the content of the first question:" ); break;
            case 3: printf( "Let us hope that this will be a successful beginning. Time for the first question in the game for a million:" ); break;
        }
        Sleep( 1000 * time_multiplier );
    }
    else if( i == 1 )
    {
        switch( temp1 % 5 )
        {
            case 0: printf( "We are fighting for the first guaranteed level. Here is the question: " ); break;
            case 1: printf( "One step separates you from the safe harbor. Here is the question for %d dollars:", rewards[ w + 1 ] ); break;
            case 2: printf( "Let us hope that this will be an easy start. Here is the question: " ); break;
            case 3: printf( "This is a crucial moment. Here is the question for %d dollars:", rewards[ w + 1 ] ); break;
            case 4: printf( "Second question, but with a key stake. The guaranteed thousand dollars. Here is your question:" ); break;
        }
        Sleep( 1000 * time_multiplier );
    }
    else if( i == 2 )
    {
        switch( temp1 % 6 )
        {
            case 0: printf( "We have the thousand dollars in our pockets already. Now we play without risk. Here is the question:" ); break;
            case 1: printf( "The first guaranteed level is behind us. You can play boldly. The question for %d dollars:", rewards[ w + 1 ] ); break;
            case 2: printf( "Nerves aside, the thousand dollars is yours. Let's see the next question:" ); break;
            case 3: printf( "Little goal achieved. Time to double the stake. Question for %d dollars:", rewards[ w + 1 ] ); break;
            case 4: printf( "You are in a safe zone. Here is the next question, this time for %d dollars", rewards[ w + 1 ] ); break;
            case 5: printf( "We breathe easier and fight for larger amounts. Here is the question:" ); break;
        }
        Sleep( 1500 * time_multiplier );
    }
    else if( i < 7 )
    {
        switch( temp1 % 8 )
        {
            case 0: printf( "You are going like a storm! Let's see the next challenge for %d dollars:", rewards[ w + 1 ] ); break;
            case 1: printf( "The stake is rising. This is no longer a joke. The question is:" ); break;
            case 2: printf( "Very good game. Keep up the pace. Here is the question:" ); break;
            case 3: printf( "Getting closer to large amounts. Focus, here is the question:" ); break;
            case 4: printf( "We are entering a higher threshold. Here is the challenge for %d dollars:", rewards[ w + 1 ] ); break;
            case 5: printf( "The path to a million is still open. Let's see the question:" ); break;
            case 6: printf( "Great job. Let's see if you know the answer to the next question:" ); break;
            case 7: printf( "The next step is before us. The game is about to get interesting. Here is the question worth %d:", rewards[ w + 1 ] ); break;
        }
        Sleep( 2000 * time_multiplier );
    }
    else if( i == 7 )
    {
        switch( temp1 % 6 )
        {
            case 0: printf( "It's a key moment. We are fighting for the second guaranteed level. Time for the question:" ); break;
            case 1: printf( "If you answer correctly, 40 thousand will be yours regardless of everything. Here is the question:" ); break;
            case 2: printf( "A game about security and large money. Here is the question for the guaranteed 40 thousand:" ); break;
            case 3: printf( "Focus at 110 percent. This is the question for the guaranteed level:" ); break;
            case 4: printf( "The second base is within reach. Here is the question for %d dollars:", rewards[ w + 1 ] ); break;
            case 5: printf( "An important moment. The guaranteed 40,000$ is waiting. Here is the question:" ); break;
        }
        Sleep( 3000 * time_multiplier );
    }
    else if( i == 8 )
    {
        switch( temp1 % 6 )
        {
            case 0: printf( "You have the guaranteed 40 thousand! You have nothing to lose. We are playing for %d$:", rewards[ w + 1 ] ); break;
            case 1: printf( "The second base is achieved. You are now playing with great comfort. Let's move on to the next question:" ); break;
            case 2: printf( "You are in the elite. The 40 thousand is yours. Let's fight for 75 thousand:" ); break;
            case 3: printf( "Great game! The guaranteed station is achieved. Let's see the next question worth 75 thousand$:" ); break;
            case 4: printf( "We take a break with relief. 40,000$ no one will take from you. We play for more:" ); break;
            case 5: printf( "A relaxed mind, a full wallet. You can take risks. The question goes:" ); break;
        }
        Sleep( 3000 * time_multiplier );
    }
    else if( i < 11 )
    {
        switch( temp1 % 7 )
        {
            case 0: printf( "It's a game of fortune. Every mistake can be costly. Question for %d$:", rewards[ w + 1 ] ); break;
            case 1: printf( "Silence in the studio... The stake is huge. Please focus. Question:" ); break;
            case 2: printf( "We are entering the area of a quarter of a million and above. Jokes are over. Question:" ); break;
            case 3: printf( "One good decision separates you from fortune. Here is the question for %d$:", rewards[ w + 1 ] ); break;
            case 4: printf( "Your heart beats faster? Mine too. Let's see what we're fighting for:" ); break;
            case 5: printf( "These are already the money that change lives. Here is the question:" ); break;
            case 6: printf( "Very high stakes. %d$ on a table. Here is the question:", rewards[ w + 1 ] ); break;
        }
        Sleep( 4000 * time_multiplier );
    }
    else
    {
        switch( temp1 % 6 )
        {
            case 0: printf( "THIS IS THE MOMENT. Question worth A MILLION DOLLARS:" ); break;
            case 1: printf( "One of 12 steps. The last one. Question worth a million:" ); break;
            case 2: printf( "History is unfolding before our eyes. The main question:" ); break;
            case 3: printf( "The final question. Will you leave here as a millionaire? Let's see:" ); break;
            case 4: printf( "Hold your breath. This is the question worth A MILLION DOLLARS:" ); break;
            case 5: printf( "The most important question in your life. A game for everything:" ); break;
        }
        Sleep( 5000 * time_multiplier );
    }

    color( 14 );
    printf( "\n%s\n", p.question );
    Sleep( 1500 * time_multiplier );
    printf( "A: %s\n", p.ansA );
    Sleep( 1000 * time_multiplier );
    printf( "B: %s\n", p.ansB );
    Sleep( 1000 * time_multiplier );
    printf( "C: %s\n", p.ansC );
    Sleep( 1000 * time_multiplier );
    printf( "D: %s\n", p.ansD );
    Sleep( 1000 * time_multiplier );

    printf( "My answer is: " );
}

void check_answer()
{
    color( 8 );
    int x = rand();
    switch( x % 12 )
    {
        case 0: printf( "Let's check...\n" ); break;
        case 1: printf( "Let's make sure...\n" ); break;
        case 2: printf( "We've marked an answer, let's see if it's correct...?\n" ); break;
        case 3: printf( "Risky... but nothing ventured, nothing gained.\n" ); break;
        case 4: printf( "Your heart beats faster? Mine too. Let's see.\n" ); break;
        case 5: printf( "Let's see if this answer is correct...\n" ); break;
        case 6: printf( "Are you sure about this 100 percent?\n" ); break;
        case 7: printf( "The silence in the audience like a field of flax...\n" ); break;
        case 8: printf( "These could be the easiest money earned in your life...\n" ); break;
        case 9: printf( "You trusted your intuition. Was it right?\n" ); break;
        case 10: printf( "The hook snapped. The decision is made.\n" ); break;
        case 11: printf( "I see hesitation on your face... But it's too late for changes.\n" ); break;
    }
}

int win( int w )
{
    if( w < 2 ) return 0;
    else if( w < 7 ) return 2;
    else if( w < 12 ) return 7;
    else return 12;
}

void defeat( int i, Question p )
{
    color( 12 );
    int random_loss = rand();
    if( i < 2 ) 
    {
        switch( random_loss % 5 )
        {
            case 0: printf( "Unfortunately, it's over. You're leaving empty handed.\n" ); break;
            case 1: printf( "That was a very short game. I'm sorry, you're leaving with 0 dollars.\n" ); break;
            case 2: printf( "Oh, that hurt. Unfortunately, wrong answer at the start.\n" ); break;
            case 3: printf( "Sometimes the nerves get the better of you. Thank you for playing.\n" ); break;
            case 4: printf( "It didn't go as planned. We're ending without a win.\n" ); break;
        }
    }
    else if( i < 7 ) 
    {
        switch( random_loss % 5 )
        {
            case 0: printf( "What a shame. It was going well. But you're leaving with a 1000 dollars.\n" ); break;
            case 1: printf( "The risk wasn't worth it, but you have a 1000 dollars to wipe away tears.\n" ); break;
            case 2: printf( "You land on your feet - 1000 dollars is yours.\n" ); break;
            case 3: printf( "A painful moment, but you're not leaving empty-handed. 1000 dollars for you.\n" ); break;
            case 4: printf( "That wasn't the correct answer. You're ending the game with a guaranteed thousand dollars.\n" ); break;
        }
    }
    else if( i < 11 ) 
    {
        switch( random_loss % 5 )
        {
            case 0: printf( "It sucks. But 40,000$ is a nice win to make you feel better.\n" ); break;
            case 1: printf( "You were one step away from a million. You're ending with a guaranteed 40,000$.\n" ); break;
            case 2: printf( "What a game! What great emotions! You're taking home 40,000$.\n" ); break;
            case 3: printf( "You risked it all for a million, but you're coming home with 40,000$. Congratulations on your courage.\n" ); break;
            case 4: printf( "Unfortunately. But 40,000$ is still a win that many would envy.\n" ); break;
        }
    }
    else 
    {
        switch( random_loss % 5 )
        {
            case 0: printf( "Oh my God! It was so close. One step away. You're taking home the guaranteed 40,000$.\n" ); break;
            case 1: printf( "You had half a million, you risked everything. Respect for your courage. You have 40,000$.\n" ); break;
            case 2: printf( "It hurts the most. You're falling at the last question. But 40,000$ is yours.\n" ); break;
            case 3: printf( "You didn't become a millionaire, but you played like a master. You're coming home with 40,000$.\n" ); break;
            case 4: printf( "Drama in the final act. The million is gone, but the guaranteed 40,000$ remains.\n" ); break;
        }
    }
    printf( "The correct answer was: %c: ", p.correct );
    switch( p.correct )
    {
        case 'A': printf( "%s", p.ansA ); break;
        case 'B': printf( "%s", p.ansB ); break;
        case 'C': printf( "%s", p.ansC ); break;
        case 'D': printf( "%s", p.ansD );
    }
}

void goodbye( int sum_won, int num_games )
{
    printf( "Thank you for playing!\n" );
    if( num_games == 1 )
        printf( "You played once\n" );
    else
        printf( "You played %d times\n", num_games );
    printf( "Your total winnings are $%d\n", sum_won );
    printf( "Your average win is $%.0lf\n", ( ( double )sum_won / num_games ) );


    system( "pause" );
}

void color( int k )
{
    HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute( hConsole, k );
}

void clean_buffer()
{
    while( getchar() != '\n' );
}