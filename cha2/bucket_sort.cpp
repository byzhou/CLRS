#include "arrayGen.h"
// in order to calculate the depth, I need math
#include <math.h>

// let's write a linked-list
class node {
    public:
        node*   nextNode ;
        int     value ;

    node(int value);

};

node::node(int value){
    nextNode   = NULL ;
    value      = value ;
}

void create_linked_list ( node* leadNode ) {
    leadNode->nextNode      = NULL ;
    leadNode->value         = -32767 ;
}

void insert_node ( node* preNode , node* currNode ) {
    
    currNode->nextNode      = preNode->nextNode ;
    preNode->nextNode       = currNode ;

}

void link_linked_lists ( node* preListLead , node* postListLead ) {

    node* currNode ; 
    for ( currNode = preListLead ; currNode->nextNode != NULL ; currNode = currNode->nextNode ) ;
    currNode->nextNode      = postListLead ;

}

int max ( int* sourceArray , int sizeOfSourceArray ) {

    // assume the largest value should be larger than this
    int largestValue = -32767 ;

    for ( int i = 0 ; i < sizeOfSourceArray ; i ++ ) {

        if ( sourceArray[i] > largestValue ) 
            largestValue = sourceArray[i] ;

    }

    return largestValue ;

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

void bucket_sort ( int* sourceArray , int sizeOfSourceArray ) {

    // counters
    int     i=0 ;
    int     bucketNum=10 ;

    node*   targetList[bucketNum] ;
    int*    targetArray ;
    node*   currNode ;


    targetArray                             = new int [sizeOfSourceArray] ;

    int     largestValueOfSourceArray       = max ( sourceArray , sizeOfSourceArray ) ;
    int     largestRadixNumberOfSourceArray = radixNumber ( largestValueOfSourceArray ) ;
    int     currRadixNum                    = 0 ;

    for ( i = 0 ; i < sizeOfSourceArray ; i ++ ) {
       
       currRadixNum = sourceArray[i] / power ( 10 , largestRadixNumberOfSourceArray ) ;

       for ( currNode = targetList[currRadixNum] ; currNode->nextNode->value < sourceArray[i]; 
               currNode = currNode->nextNode )
           if ( currNode->nextNode == NULL )
               break ;
      
       node* newNode = new node ; 
       newNode->value = sourceArray[i] ;

       insert_node ( currNode , newNode ) ;
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
    bucket_sort ( testArray , sizeOfTestArray ) ;

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

 
