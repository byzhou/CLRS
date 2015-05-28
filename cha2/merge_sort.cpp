#include "arrayGen.h"
// in order to calculate the depth, I need math
#include <math.h>

int main () {

    // counters 
    int     i=0 , j=0 , k=0 , m=0 ;

    // initializing test array
    int*    testArray ;
    int     sizeOfTestArray  = 10 ; 
    int     inserted_num ;
    int*    mergedArrary ;
    testArray           = new int [sizeOfTestArray]  ;
    mergedArrary        = new int [sizeOfTestArray]  ;

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

    // first round sorting
    for ( i = 0 ; i < sizeOfTestArray ; i += 2 ) {
        if ( testArray[i] > testArray[i + 1] ) {
            swapTmp             = testArray[i + 1] ;
            testArray[i + 1]    = testArray[i] ;
            testArray[i]        = swapTmp ;
        }
    }

    printf ( "This is 0th round!\n " ) ;
    print_array ( testArray , sizeOfTestArray ) ;

    // second round and so on
    for ( i = 1 ; i <= hierarchyDepth ; i ++ ) {
        printf ( " Start %dth layer Sorting ... \n " , i ) ;
        // for each depth the number of merging times is determined
        mergeTimes  = ceil ( sizeOfTestArray / pow ( 2 , i ) ) ;
        mergeLength = pow ( 2 , i ) ;

        // k is the first source sub-array's pointer
        // m is the second source sub-array's pointer
        k           = 0 ;
        m           = mergeLength ;
        
        // j is the target array's pointer
        for ( j = 0 ; j < sizeOfTestArray ; j ++ ) {

            printf ( "k=%d, m=%d\n" , k , m ) ;
            
            // Firstly, we need to check whether the pointer is out of bound
            // If it is out of bound, we just stop the loop
            if ( ( k >= ( sizeOfTestArray - 1 ) ) && 
                 ( m >= ( sizeOfTestArray - 1 ) ) ) {
                break ;
                printf ( "case 1 \n" ) ;

            // if one of the two source pointers are out of bound
            // k is in the array, m is out of the array
            } else if ( ( k <= ( sizeOfTestArray - 1 ) ) && 
                        ( m >= ( sizeOfTestArray - 1 ) ) ) {
                break; 
            // m is in the array, k is out of the array
            } else if ( ( m <= ( sizeOfTestArray - 1 ) ) && 
                        ( k >= ( sizeOfTestArray - 1 ) ) ) {
                break; 
            // one of the sequences is shorter than the other and it reaches the
            // end while the other does not

            } else if ( ( ( ( k + 1 ) % mergeLength )         == 0 ) && 
                            ( k == ( sizeOfTestArray - 1 )  ) &&
                            ( m + 1 ) % ( 2 * mergeLength )   != 0 ) {
            // if the one of two source pointers are targeting the end of the sequences
            } else if ( ( ( ( k + 1 ) % mergeLength )         == 0 ) && 
                            ( m + 1 ) % ( 2 * mergeLength )   != 0 ) {
                    mergedArrary[j] = testArray[m] ;
                    m++ ;
                printf ( "case 3 \n" ) ;

            // if the one of two source pointers are targeting the end of the sequences
            } else if ( ( ( ( k + 1 ) % mergeLength )         != 0 ) && 
                            ( m + 1 ) % ( 2 * mergeLength )   == 0 ) {
                    mergedArrary[j] = testArray[k] ;
                    k++ ;
                printf ( "case 4 \n" ) ;

            // if the two source pointers are targeting the end of the sequences
            } else if ( ( ( ( k + 1 ) % mergeLength )         == 0 ) && 
                            ( m + 1 ) % ( 2 * mergeLength )   == 0 ) {
            
                // if one sub string has been merged
                k += ( mergeLength + 1 ) ;
                m += ( mergeLength + 1 ) ;

                printf ( "case 2 \n" ) ;

            } else {

                // k is the first source sub-array's pointer
                // m is the second source sub-array's pointer
                if ( testArray[k] > testArray[m] ) {
                    mergedArrary[j] = testArray[m] ;
                    m++ ;
                } else {
                    mergedArrary[j] = testArray[k] ;
                    k++ ;
                }

                printf ( "case 5 \n" ) ;

            }

        }

        printf ( " This is after %dth layer Sorting ... \n " , i ) ;
        copy_array  ( testArray    , mergedArrary , sizeOfTestArray ) ;
        print_array ( mergedArrary , sizeOfTestArray ) ;
        
    }

    // after sorting
    printf ( "This is after sorting.\n" ) ;
    print_array ( mergedArrary , sizeOfTestArray ) ;

    // testing
    if ( test_array_been_sorted ( mergedArrary , sizeOfTestArray ) )
        system ( " figlet SORTING SUCCESS ! \n " ) ;
    else
        system ( " figlet SORTING FAILED ! \n " ) ;

    delete[] testArray ;
    delete[] mergedArrary ;
    
    return 0 ;

}

 
