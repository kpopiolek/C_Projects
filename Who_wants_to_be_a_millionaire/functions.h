#pragma once

#include "questions.h"

int win( int w );
void print_q( Question p, int w, int i, int is_5050, int is_audience, int is_phone, int time_multiplier );
void greetings();
void goodbye( int sum_won, int num_games );
void check_answer();
void defeat( int i, Question p );
void color( int k );
void millionaire();
void clean_buffer();
