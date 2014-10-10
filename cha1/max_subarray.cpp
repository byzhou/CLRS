#include <iostream>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include <stdio.h>

using namespace std;

const int neg_infinity  = 0xFFFFFFFF ;
const int pos_infinity  = 0x7FFFFFFF ;

void print_array ( int* array , int num ) ;
void diff_array ( int* array, int* diff_array ) ;
void max_cross_subarray ( int* array , int& left , int mid , int& right ) ;

struct left_right {
    int left ;
    int right ;
    int sum ;
};

/*  For a given array, this function print out the array's
 *  elements.
 */
void print_array ( int* array , int num ) {
    printf ( "Below is the the array: \n " ) ;
    for ( int i = 0 ; i < num ; i ++ ) {
        printf ( "%d \t", array[i] ) ;
    }
    printf ( "\n " ) ;
}

/*  This function will take the diff between two elements of an
 *  array.
 */
void diff_array ( int* array , int* diff_array ) {
    if ( (array + 1) == NULL )
        printf ( " This array has too less elements. \n " ) ;
    for ( int i = 0 ; (array + i + 1) != NULL ; i ++ ) 
        diff_array[i] = array[i+1] - array[i];
}

struct left_right max_cross_subarray ( int* array , int left , int mid , int right ) {

    int left_sum    = neg_infinity ;
    int right_sum   = neg_infinity ;
    int sum         = 0 ;
    int i           = 0 ;
    int return_left = 0 ;
    int return_right= 0 ;
    struct left_right tmp;

    if (left == mid || mid == right || left == right)
        return 0;

    for ( i = mid ; i > left ; i -- ) {
        sum     += array[i] ;
        if ( sum > left_sum )
            left_sum    = sum ;
            return_left = i ;
    }
    tmp.left    = return_left ;

    for ( i = mid ; i < right ; i ++ ) {
        sum     += array[i] ;
        if ( sum > right_sum )
            right_sum       = sum ;
            return_right    = i ;
    }
    tmp.right   = return_right ;

    tmp.sum     = left_sum + right_sum ;

    return tmp;
}

struct left_right max_subarray ( int* array , int left , int right ) {
    int left_sum        = neg_infinity ;
    int right_sum       = neg_infinity ;
    int mid_sum         = neg_infinity ;
    int mid             = (left + right) / 2 ;
    struct left_rigth   tmp ;
    tmp.left            = left ;
    tmp.right           = right ;
    tmp.sum             = array[left] ;

    if (left == right)
        return tmp ;
    else {
        left_sum        = max_subarray ( array , left , mid ) . sum ;
        right_sum       = max_subarray ( array , mid , right ) . sum ;
        mid_sum         = max_cross_subarray ( array , left , mid , right ) . sum ;
        if ( ( left_sum >= right_sum ) && ( left_sum >= mid_sum ) )
            return max_subarray ( array , left , mid ) ;
        if ( ( right_sum >= left_sum ) && ( right_sum >= mid_sum ) )
            return max_subarray ( array , mid , right ) ;
        if ( ( mid_sum >= left_sum ) && ( mid_sum >= right_sum ) )
            return max_cross_subarray ( array , left , mid , right ) ;
    }
}


int main(){
    //length of the array
    const int num = 3;
    //random generator seed
    srand(time(0));
    //time generation
    clock_t t;


    int array[num*num];
    int i,j;

    //record start time
    t = clock();
    for ( i = 0; i < num; i++ ) {
          for ( j = 0; j < num; j ++ ) {
            array[i * num + j]      = rand() / 1000000 ;
            printf( "array %d value is %d \n", i*num + j, array[i * num + j] ) ;
          }
    }

    printf( "The time spent on the array generation is: %4.2f \n", (float)( clock() - t) / CLOCKS_PER_SEC ) ;    

    long double key;
    //record start time
    
    //record end time
    printf( "The time spent on the array sorting is: %4.2f \n", (float)( clock() - t) / CLOCKS_PER_SEC );
    cout<<"The array has been sorted."<<endl;

    //print the sorted array
    for ( i = 0; i < num; i++ ) {
          for ( j = 0 ; j < num ; j++ ) {
            printf( "array %d value is %d \n", i * num + j , array[i * num + j] ) ;
          }
    }
    
    return 0;
}
