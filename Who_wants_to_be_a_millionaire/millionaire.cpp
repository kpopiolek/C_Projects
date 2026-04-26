#include "lifelines.h"
#include <windows.h>
#include <time.h>
#include "functions.h"
#include "questions.h"

int main()
{
    srand( ( unsigned )time( NULL ) );
    system( "cls" );

    millionaire();

    return 0;
}
