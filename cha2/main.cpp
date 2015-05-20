#include <stdio.h>
#include <stdlib.h>

#include "arrayGen.h"

int main () {
    int* test ;
    test = new int (4 * sizeof ( int ) )  ;

    integer_random_number_generator ( test, 4 )  ;
    printf ( "test" ) ;
    printf ( " hello world \n" ) ;
}
