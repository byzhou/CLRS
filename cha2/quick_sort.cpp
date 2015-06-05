#include "arrayGen.h"
// in order to calculate the depth, I need math
#include <math.h>

// swap values within an array
void swap ( int* testArray , int elementA , int elementB ) {

    int tmp     = 0 ;

    tmp                 = testArray[elementA] ;
    testArray[elementA] = testArray[elementB] ;
    testArray[elementB] = tmp ;

}

// partition for the quick_sort
int partition ( int* testArray , int startIndex , int endIndex ) {

    int endOfSmallSub       = startIndex - 1 ;
    int counter             = startIndex ;
    int reference           = testArray[endIndex] ;

    // we need to have the reference to stay in one place during the entire sorting, so we keep it
    // in the endIndex. The partition will put the the elements smaller than the reference to the
    // left of endOfSmallSub, and elements larger than the reference right of the endOfSmallSub + 1.
    // In the end, we need to swap the last element, which is the reference element to the mid
    // position in order to complete the sorting.
    for ( counter = startIndex ; counter < endIndex ; counter ++ ) {
        
        // the current pointed element is smaller than the eventual midpoint
        if ( testArray[counter] < reference ) {

            endOfSmallSub ++ ;
            // swap the value of the end of the small sub and the current element
            swap ( testArray, endOfSmallSub, counter ) ;

        }

        // printf ( " This print is in the loop of partition.\n" ) ;
        // print_array ( testArray , startIndex , endIndex ) ;

    }

    // last swap for the last element 
    swap ( testArray , ++endOfSmallSub , endIndex ) ;

    // This is after the last operation of partition
    // printf ( " This is after the last operation of partition.\n" ) ;
    // printf ( " endOfSmallSub is equal to %d \n " , endOfSmallSub ) ;
    // print_array ( testArray , startIndex , endIndex ) ;

    // endOfSmallSub has already incremented
    return endOfSmallSub ;

}

void quick_sort ( int* testArray , int startIndex , int endIndex ) {

    int midIndex = 0 ;

    if ( startIndex < endIndex ) {
    
        // find out the midpoint and partition the the array into two parts
        midIndex = partition ( testArray , startIndex , endIndex ) ;
        // printf ( " startIndex = %d , endIndex = %d , midIndex = %d \n " ,
        //             startIndex , endIndex , midIndex ) ;

        // recursively call the the quick sort function for the two subarrays
        quick_sort ( testArray , startIndex , midIndex - 1 ) ;
        quick_sort ( testArray , midIndex + 1 , endIndex ) ;
        
    } else {

        // print_array ( testArray , startIndex , endIndex ) ;

    }
}

void run_quick_sort ( int* testArray , int sizeOfTestArray ) {

    quick_sort ( testArray , 0 , sizeOfTestArray - 1 ) ;

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
    run_quick_sort ( testArray , sizeOfTestArray ) ;
    // partition ( testArray , 0 , sizeOfTestArray - 1 ) ;

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

 
