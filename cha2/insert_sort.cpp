#include "arrayGen.h"

int main () {

    // counters
    int     i=0 , j=0 , k=0 ;

    // initializing test array
    int*    testArray ;
    int     sizeOfTestArray  = 10 ; 
    int     inserted_num ;
    testArray = new int [sizeOfTestArray]  ;

    // random generation
    integer_random_number_generator ( testArray , sizeOfTestArray ) ;

    // before sorting
    // printf ( "This is before sorting.\n" ) ;
    // print_array ( testArray , sizeOfTestArray ) ;

    for ( i = 0 ; i <= sizeOfTestArray - 1 ; i ++ ) {
        // move to the place that the element is larger than all the elements
        // larger then it 
        for ( j = 0 ; 
                ( testArray[j] < testArray[i] ) && ( j <= i ) ;
                j ++ ) ;

        // I am afraid it will overwrite
        inserted_num = testArray[i] ;
        
        // move all the numbers from j to i one step back
        for ( k = i ; ( i != j ) && ( k >= j ) ; k -- ) 
            testArray [k] = testArray [k - 1] ;

        // fill the empty spot
        testArray[j] = inserted_num ;
    }

    // after sorting
    // printf ( "This is after sorting.\n" ) ;
    // print_array ( testArray , sizeOfTestArray ) ;

    // testing
    if ( test_array_been_sorted ( testArray , sizeOfTestArray ) )
        printf ( " SORTING SUCCESS ! \n " ) ;
    else
        printf ( " SORTING FAILED ! \n " ) ;

    delete[] testArray ;
    
    return 0 ;

}

