#include "arrayGen.h"
// in order to calculate the depth, I need math
#include <math.h>

int parent ( int i ) {
    return ( ( int ) floor ( ( i + 1) / 2 ) - 1 ) ;
}

int left ( int i ) {
    return ( ( int ) floor ( 2 * i + 2 ) - 1 ) ;
}

int right ( int i ) {
    return ( ( int ) floor ( 2 * i + 1 + 2 ) - 1 ) ;
}

// This function will ensure the root of the heap is always the largest element in the heap.
void max_heapify ( int* testArray , int iIndex , int sizeOfHeap ) {
    
    int lIndex=0 , rIndex=0 , largestIndex=0 ;
    int tmp=0 ;
    lIndex      = left  ( iIndex ) ;
    rIndex      = right ( iIndex ) ;

    // find out the largest value in the one parent, brothers structure
    if ( ( lIndex < sizeOfHeap ) && ( testArray[lIndex] > testArray[iIndex] ) )
        largestIndex    = lIndex ;
    else
        largestIndex    = iIndex ;

    if ( ( rIndex < sizeOfHeap ) && ( testArray[rIndex] > testArray[largestIndex] ) )
        largestIndex    = rIndex ;
    
    // if the largest value is not in the middle, change it to the middle one
    // pass the small value down into the bottom of the heap
    if ( largestIndex != iIndex ) {
        printf ( " Before Swap \n " ) ;
        printf ( " lIndex: testArray[%d] = %d " , lIndex , testArray[lIndex] ) ;
        printf ( " rIndex: testArray[%d] = %d " , rIndex , testArray[rIndex] ) ;
        printf ( " iIndex: testArray[%d] = %d \n" , iIndex , testArray[iIndex] ) ;
        printf ( " largestIndex: testArray[%d] = %d \n" , largestIndex , testArray[largestIndex] ) ;

        // switch the largest value with the middle value
        tmp                     = testArray[largestIndex] ;
        testArray[largestIndex] = testArray[iIndex] ;
        testArray[iIndex]       = tmp ;
        printf ( " After  Swap \n " ) ;
        printf ( " lIndex: testArray[%d] = %d " , lIndex , testArray[lIndex] ) ;
        printf ( " rIndex: testArray[%d] = %d " , rIndex , testArray[rIndex] ) ;
        printf ( " iIndex: testArray[%d] = %d \n" , iIndex , testArray[iIndex] ) ;
        printf ( " largestIndex: testArray[%d] = %d \n" , largestIndex , testArray[largestIndex] ) ;
        printf ( " Going to a deeper recursion.\n " ) ;

        printf ( " Going to a deeper recursion.\n " ) ;
        // recursive
        max_heapify ( testArray , largestIndex , sizeOfHeap ) ;
    } else {

        printf ( " lIndex: testArray[%d] = %d " , lIndex , testArray[lIndex] ) ;
        printf ( " rIndex: testArray[%d] = %d " , rIndex , testArray[rIndex] ) ;
        printf ( " iIndex: testArray[%d] = %d \n" , iIndex , testArray[iIndex] ) ;
        printf ( " largestIndex: testArray[%d] = %d \n" , largestIndex , testArray[largestIndex] ) ;

    }
        
}

void build_heap ( int* testArray , int sizeOfHeap ) {

    int i=0 ;

    // build the heap from the second half of the heap
    for ( i = ( sizeOfHeap / 2 ) ; i >= 0 ; i -- ) {
        max_heapify ( testArray , i , sizeOfHeap - i ) ;
    }

}

void heap_sort ( int* testArray , int sizeOfTestArray ) {

    int i=0 ;
    int tmp=0 ;

    build_heap ( testArray , sizeOfTestArray ) ;
    printf ( "After building the heap for the first time.\n" ) ;
    print_array ( testArray , sizeOfTestArray ) ;

    for ( i = sizeOfTestArray - 1 ; i >=0 ; i-- ) {
        // exchange the last element with the first element, since the first element is the always
        // the largest value in the heap
        tmp             = testArray[i] ;
        testArray[i]    = testArray[0] ;
        testArray[0]    = tmp ;

        printf ( "After heaping each time.\n" ) ;
        print_array ( testArray , sizeOfTestArray ) ;

        max_heapify ( testArray , 1 , i )  ;
    }

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
    heap_sort ( testArray , sizeOfTestArray ) ;

    // after sorting
    printf ( "This is after sorting.\n" ) ;
    print_array ( testArray , sizeOfTestArray ) ;

    // testing
    if ( test_array_been_sorted ( testArray , sizeOfTestArray ) )
        system ( " figlet SORTING SUCCESS ! \n " ) ;
    else
        system ( " figlet SORTING FAILED ! \n " ) ;

    delete[] testArray ;
    
    return 0 ;

}

 
