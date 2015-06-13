#include "arrayGen.h"
// in order to calculate the depth, I need math
#include <math.h>

int max ( int* sourceArray , int sizeOfSourceArray ) {

    // assume the largest value should be larger than this
    int largestValue = -32767 ;

    for ( int i = 0 ; i < sizeOfSourceArray ; i ++ ) {

        if ( sourceArray[i] > largestValue ) 
            largestValue = sourceArray[i] ;

    }

    return largestValue ;

}

// suppose counting sort is to sort the nature number
void counting_sort ( int* sourceArray , int sizeOfSourceArray ) {

    // counter
    int     i=0 ;
    
    int*    targetArray ;
    int*    tmpArray ;
    int     largestValueOfSourceArray = max ( sourceArray , sizeOfSourceArray ) ;

    targetArray         = new int [sizeOfSourceArray] ;
    tmpArray            = new int [largestValueOfSourceArray + 1] ;

    // initialization
    for ( i = 0 ; i < ( largestValueOfSourceArray + 1 ) ; i ++ ) 
        tmpArray[i]     = 0 ;

    // counting the number of appearance of each value
    for ( i = 0 ; i < sizeOfSourceArray ; i ++ ) 
        tmpArray[sourceArray[i]] ++ ;

    // calculate the cumulative number of appearance
    for ( i = 1 ; i < ( largestValueOfSourceArray + 1 ) ; i ++ ) 
        tmpArray[i] += tmpArray[i - 1] ;

    // put the source array elements into the right places
    for ( i = 0 ; i < sizeOfSourceArray ; i ++ ) {
        // the source array element goes to the index of number of elements smaller than it
        targetArray[tmpArray[sourceArray[i]] - 1] = sourceArray[i] ; 
        // after place one, reduce the number of elements
        tmpArray[sourceArray[i]] -- ;
    }

    copy_array ( sourceArray , targetArray , sizeOfSourceArray ) ;


    delete[] targetArray ;
    delete[] tmpArray ;

}


int main () {

    // counters 
    int     i=0 , j=0 , k=0 , m=0 ;

    // initializing test array
    int*    testArray ;
    int     sizeOfTestArray  = 10 ; 
    int     inserted_num ;
    testArray           = new int [sizeOfTestArray]  ;

    // random generation
    integer_random_number_generator ( testArray , sizeOfTestArray ) ;

    // before sorting
    printf ( "This is before sorting.\n" ) ;
    print_array ( testArray , sizeOfTestArray ) ;

    // depth for loop
    printf ( " Start Sorting ... \n " ) ;

    // This part is the sorting
    counting_sort ( testArray , sizeOfTestArray ) ;

    // after sorting
    printf ( "This is after sorting.\n" ) ;
    print_array ( testArray , sizeOfTestArray ) ;

    // testing
    if ( test_array_been_sorted ( testArray , sizeOfTestArray ) )
        system ( " echo SORTING SUCCESS ! \n " ) ;
    else
        system ( " echo SORTING FAILED ! \n " ) ;

    delete[] testArray ;
    
    return 0 ;

}

 
