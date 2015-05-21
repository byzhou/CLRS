#include "arrayGen.h"

void integer_random_number_generator ( int* randomArray , int sizeOfArray ) {
    // time seed 
    srand ( time ( NULL ) ) ;

    for ( int i = 0 ; i < sizeOfArray ; i ++ ) 
        * ( randomArray + i )  = rand() % 100 + 1 ;
}

void double_random_number_generator ( int* randomArray , int sizeOfArray ) {

    // time seed 
    srand ( time ( NULL ) ) ;

    for ( int i = 0 ; i != sizeOfArray ; i ++ ) 
        * ( randomArray + i )   = rand() % 10 + 1 ;
}

void print_array ( int* randomArray , int sizeOfArray ) {

    for ( int i = 0 ; i < sizeOfArray ; i ++ ) 
        printf ( "%d\n" , * ( randomArray + i ) ) ;

}

bool test_array_been_sorted ( int* randomArray , int sizeOfArray ) {

    for ( int i = 0 ; i < sizeOfArray - 1 ; i ++ ) {
        if ( randomArray [i] > randomArray [i + 1] ) 
            return false ;
    }
    return true ;
}

void copy_array ( int* targetArray , int* sourceArray , int sizeOfArray ) {

    for ( int i = 0 ; i < sizeOfArray ; i ++ ) 
        targetArray[i] = sourceArray[i] ;

}
