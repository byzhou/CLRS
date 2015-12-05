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
        targetArray[tmpArray[sourceArray[i]]] = sourceArray[i] ; 
        // after place one, reduce the number of elements
        tmpArray[sourceArray[i]] -- ;
    }

    copy_array ( sourceArray , targetArray , sizeOfSourceArray ) ;

    delete[] targetArray ;
    delete[] tmpArray ;

}

// find out the radix number of a value
int radixNumber ( int findRadixNumberOfThisInt ) {

    int returnValue=0 ;

    // end condition
    if ( findRadixNumberOfThisInt / 10 == 0 ) {
        return (int) 1 ;
    } else {
        // recursive tests
        returnValue = radixNumber ( findRadixNumberOfThisInt / 10 ) ;
        returnValue++ ;
        return returnValue ;
    }

}

int power ( int base , int powerNum ) {

    if ( powerNum == 0 )
        return 1 ;
    else
        return base * power ( base , powerNum - 1 ) ;

}

// Generating the radix sort reference
void radixRefGen ( int* sourceArray , int sizeOfSourceArray , 
                    int* counting_sort_ref , int radixNowSorting ) {

    int i=0 ;

    for ( i = 0 ; i < sizeOfSourceArray ; i ++ ) 
        counting_sort_ref[i]    = sourceArray[i] % power ( 10 , radixNowSorting + 1 ) 
                                                 / power ( 10 , radixNowSorting ) ;
}

// the core sorting algorithm is counting_sort
void radix_sort ( int* sourceArray , int sizeOfSourceArray ) {

    // counter
    int     i=0 , j=0 ;

    int*    counting_sort_ref ;
    int*    targetArray ;
    int*    tmpArray ;

    // creating the dynamic arrays
    counting_sort_ref       = new int [sizeOfSourceArray] ;
    tmpArray                = new int [10] ;
    targetArray             = new int [sizeOfSourceArray] ;



    // get the largest radix number of the array, but first, I need to get the largest value
    int     largestValueOfSourceArray       = max ( sourceArray , sizeOfSourceArray ) ;
    int     largestRadixNumberOfSourceArray = radixNumber ( largestValueOfSourceArray ) ;

    for ( i = 0 ; i < largestRadixNumberOfSourceArray ; i ++ ) {
        // sorting on each radix

        // find out the radix value of each number as the sorting refs
        radixRefGen ( sourceArray , sizeOfSourceArray , counting_sort_ref , i ) ;

        // #define radix_extraction_test 
        // #define single_radix_sort_test
        // #define tmpArray_test

        #ifdef radix_extraction_test
          printf ( "%dth radix, ref values \n " , i ) ;
          print_array ( counting_sort_ref , sizeOfSourceArray ) ;
          printf ( "\n\n\n" ) ;
        #endif
        
        for ( j=0 ; j<10 ; j++ ) 
            tmpArray[j] = 0 ;
    
        for ( j=0 ; j<sizeOfSourceArray ; j++ ) 
            tmpArray[counting_sort_ref[j]] ++ ;

        #ifdef tmpArray_test
            printf ( "before accumulation %dth tmpArray test \n " , i) ;
            print_array ( tmpArray , 10 ) ;
            printf ( "\n\n\n\n\n" ) ;
        #endif 

        for ( j=1 ; j<10 ; j++ ) 
            tmpArray[j] += tmpArray[j - 1] ;

        #ifdef tmpArray_test
            printf ( "after accumulation %dth tmpArray test \n " , i) ;
            print_array ( tmpArray , 10 ) ;
            printf ( "\n\n\n\n\n" ) ;
        #endif 

        #ifdef single_radix_sort_test
            printf ( "before final sort, test source array, %dth radix \n " , i ) ;
            print_array ( sourceArray , sizeOfSourceArray ) ;
            printf ( "\n\n\n" ) ;
            printf ( "before final sort, test target array, %dth radix \n " , i ) ;
            print_array ( targetArray , sizeOfSourceArray ) ;
            printf ( "\n\n\n" ) ;
        #endif

        for ( j=(sizeOfSourceArray - 1) ; j>= 0 ; j-- ){
            targetArray[tmpArray[counting_sort_ref[j]] - 1] = sourceArray[j] ;
            tmpArray[counting_sort_ref[j]] -- ;
        }

        copy_array ( sourceArray , targetArray , sizeOfSourceArray ) ;

        #ifdef single_radix_sort_test
            printf ( "%dth radix, sorted values \n " , i ) ;
            print_array ( targetArray , sizeOfSourceArray ) ;
            printf ( "\n\n\n" ) ;
        #endif

    }


    delete[] targetArray ;
    delete[] tmpArray ;    
    delete[] counting_sort_ref ;

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
    radix_sort ( testArray , sizeOfTestArray ) ;

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

 
