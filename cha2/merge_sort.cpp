#include "arrayGen.h"
// in order to calculate the depth, I need math
#include <math.h>

int* merge_sort ( int* startOfFirstArray , int* startOfSecondArray ,
                    int sizeOfFirstArray , int  sizeOfSecondArray ) {
    // some counters 
    int     i=0 , j=0 , k=0 ;

    // initialization
    int*    targetArray ;
    int     totalLength = sizeOfFirstArray + sizeOfSecondArray ;

    targetArray     = new int [ totalLength ] ;

    // printf ( " Start Merging\n " ) ;
    // printf ( " size of the first array %d \t " , sizeOfFirstArray ) ;
    // printf ( " size of the second array %d \n " , sizeOfSecondArray ) ;

    if ( startOfFirstArray == startOfSecondArray ) {
        // printf ( " Stop Merging\n" ) ;
        // print_array ( startOfFirstArray , 1 )  ;
        return startOfFirstArray ;
    } else {
    
        merge_sort ( startOfFirstArray , 
                     startOfFirstArray + ( int ) floor ( sizeOfFirstArray / 2 ) , 
                     ( int ) floor ( sizeOfFirstArray / 2 ) , 
                     sizeOfFirstArray - ( int ) floor ( sizeOfFirstArray / 2 ) 
                     ) ;
        
        merge_sort ( startOfSecondArray , 
                     startOfSecondArray + ( int ) floor ( sizeOfSecondArray / 2 ) , 
                     ( int ) floor ( sizeOfSecondArray / 2 ) , 
                     sizeOfSecondArray - ( ( int ) floor ( sizeOfSecondArray / 2 ) )
                     ) ;
    
    }

    // i is the counter of the target array
    for ( i = 0 ; i < totalLength ; i ++ ) {
        // j is the counter of the first array , k is the counter 
        // of the second array.
        if ( j == sizeOfFirstArray ) {
            // the end of the first array
            targetArray [i] = startOfSecondArray [k] ;
            k++;
            // printf ( " case 1 \n " ) ;
        } else if ( k == sizeOfSecondArray ) {
            // the end of the second array
            targetArray [i] = startOfFirstArray [j] ;
            j++;
            // printf ( " case 2 \n " ) ;
        } else if ( startOfFirstArray [j] < startOfSecondArray [k] ) {
            // common situation just do the comparison and move the pointer
            targetArray [i] = startOfFirstArray [j];
            j++;
            // printf ( " case 3 \n " ) ;
        } else {
            // common situation just do the comparison and move the pointer
            targetArray [i] = startOfSecondArray [k];
            k++;
            // printf ( " case 4 \n " ) ;
        }

    }

    // suppose that the two arrays are consecutive
    copy_array ( startOfFirstArray , targetArray , totalLength ) ;

    // printf ( " Merging Completed. Target length is %d.\n " , totalLength ) ;
    // print_array ( startOfFirstArray , totalLength ) ;

    delete[] targetArray ;

}

int main () {

    // counters 
    int     i=0 , j=0 , k=0 , m=0 ;

    // initializing test array
    int*    testArray ;
    int     sizeOfTestArray  = 10 ; 
    int     inserted_num ;
    testArray           = new int [sizeOfTestArray]  ;

    // set the depth
    int     hierarchyDepth = ( int ) ceil ( log2 ( sizeOfTestArray ) ) ;
    int     mergeTimes  = 0 ;
    int     mergeLength = 0 ;
    int     swapTmp     = 0 ;

    // random generation
    integer_random_number_generator ( testArray , sizeOfTestArray ) ;

    // before sorting
    printf ( "This is before sorting.\n" ) ;
    print_array ( testArray , sizeOfTestArray ) ;

    // depth for loop
    printf ( " Start Sorting ... \n " ) ;

    merge_sort ( testArray , testArray + ( int ) floor ( sizeOfTestArray / 2 ) , 
                     ( int ) floor ( sizeOfTestArray / 2 ) , 
                     sizeOfTestArray - ( ( int ) floor ( sizeOfTestArray / 2 ) )
                 ) ;

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

 
