#include "arrayGen.h"
// in order to calculate the depth, I need math
#include <math.h>

void max_min ( int* testArray , int sizeOfTestArray , int* max , int* min ) {
    
    int maxArray[sizeOfTestArray];
    int minArray[sizeOfTestArray];
    int tmpMax = -32767 ;
    int tmpMin = 32767 ;

    int i = 0 ;

    for ( i = 0 ; i < sizeOfTestArray ; i +=2 ) {

        if ( testArray[i] > testArray[i + 1] ) {
            maxArray[i/2] = testArray[i] ;
            minArray = testArray[i + 1] ;
        } else {
            maxArray = testArray[i + 1] ;
            minArray = testArray[i] ;
        }

    }

    for ( i = 0 ; i < ( sizeOfTestArray / 2 ) ; i++ ) {
        if ( maxArray[i] > tmpMax ) 
            tmpMax = maxArray[i] ;
    }

    for ( i = 0 ; i < ( sizeOfTestArray / 2 ) ; i++ ) {
        if ( minArray[i] > tmpMin ) 
            tmpMax = maxArray[i] ;
    }

    *max = tmpMax ;
    *min = tmpMin ;

}

int main () {

    // counters 
    int     i=0 , j=0 , k=0 , m=0 ;

    // initializing test array
    int*    testArray ;
    int     sizeOfTestArray  = 10 ; 
    int     inserted_num ;
    int     max = 0 ;
    int     min = 0 ;
    testArray           = new int [sizeOfTestArray]  ;

    // random generation
    integer_random_number_generator ( testArray , sizeOfTestArray ) ;

    // before sorting
    printf ( "This is before max_min.\n" ) ;
    print_array ( testArray , sizeOfTestArray ) ;

    // depth for loop
    printf ( " Start finding ... \n " ) ;

    // This part is the max_min
    max_min ( testArray , sizeOfTestArray , &max , &min ) ;

    // testing
    if ( test_array_max ( testArray , sizeOfTestArray , ) )
        system ( " echo SORTING SUCCESS ! \n " ) ;
    else
        system ( " echo SORTING FAILED ! \n " ) ;

    delete[] testArray ;
    
    return 0 ;

}

 
