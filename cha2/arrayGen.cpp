#include "arrayGen.h"

int random_number_generator ( int lowerBound , int upperBound ) {

    //time seed 
    srand ( time ( NULL ) ) ;

    int rangeOfRandom       = upperBound - lowerBound + 1 ; 

    int my_random_number    = rand () % rangeOfRandom + lowerBound ; 

    return my_random_number ;

}

void integer_random_number_generator ( int* randomArray , int sizeOfArray ) {
    // time seed 
    srand ( time ( NULL ) ) ;

    for ( int i = 0 ; i < sizeOfArray ; i ++ ) 
        * ( randomArray + i )  = rand() % 100 + 1 ;
}

void integer_random_number_generator ( int* randomArray , int lowerBound , int upperBound ) {
    // time seed 
    srand ( time ( NULL ) ) ;

    for ( int i = 0 ; i < ( upperBound - lowerBound + 1 ) ; i ++ ) 
        * ( randomArray + i )  = rand() % ( upperBound - lowerBound + 1 ) + lowerBound ;
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

void print_array ( int* randomArray , int startIndex , int endIndex ) {

    for ( int i = startIndex ; i <= endIndex ; i ++ ) 
        printf ( "%d\n" , randomArray[i] ) ;

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
