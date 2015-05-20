#include "arrayGen.h"

void integer_random_number_generator ( int* randomArray , int sizeOfArray ) {
    // time seed 
    srand ( time ( NULL ) ) ;

    for ( int i = 0 ; i != sizeOfArray ; i ++ ) {
        * ( randomArray + i )  = rand() % 10 + 1 ;
        printf ( " The random number is %d \n " , * ( randomArray + i )  ) ;
    }

        
}

void double_random_number_generator ( int* randomArray , int sizeOfArray ) {

    // time seed 
    srand ( time ( NULL ) ) ;

    for ( int i = 0 ; i != sizeOfArray ; i ++ ) {
        * ( randomArray + i )   = rand() % 10 + 1 ;
        printf ( " The random number is %d \n " , * ( randomArray + i ) ) ;
    }
}

