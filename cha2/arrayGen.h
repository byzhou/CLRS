#ifndef _ARRAYGEN_H_
#define _ARRAYGEN_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// integer random number generator
void integer_random_number_generator ( int* randomArray , int sizeOfArray ) ;

// double random number generator
void double_random_number_generator ( int* randomArray , int sizeOfArray ) ;

// print all the array
void print_array ( int* randomArray , int sizeOfArray ) ;

bool test_array_been_sorted ( int* randomArray , int sizeOfArray ) ;
void copy_array ( int* targetArray , int* sourceArray , int sizeOfArray ) ;
#endif
