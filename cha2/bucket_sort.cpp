#include "arrayGen.h"
// in order to calculate the depth, I need math
#include <math.h>

// let's write a linked-list
class node {
    public:
        node*   nextNode ;
        int     value ;

    node() ;
    node(int value);

};

// constructor
node::node() {
    nextNode    = NULL ;
    value       = -32767 ;
}

node::node(int value){
    nextNode    = NULL ;
    value       = value ;
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

    if ( preListLead == NULL ) {
        preListLead = postListLead ;
        return ;
    }

    if ( postListLead == NULL ) {
        postListLead = preListLead ;
        return ;
    }
            
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

int power ( int base , int powerNum ) {

    if ( powerNum == 0 )
        return 1 ;
    else
        return base * power ( base , powerNum - 1 ) ;

}

void bucket_sort ( int* sourceArray , int sizeOfSourceArray ) {

    // counters
    int     i           =0 ;
    // bucket number
    int     bucketNum   =10 ;

    node*   targetList[bucketNum] ;
    int*    targetArray ;
    node*   currNode ;

    targetArray                             = new int [sizeOfSourceArray] ;
    for ( i = 0 ; i < sizeOfSourceArray ; i ++ ) {
        targetList[i]       = new node ;
        create_linked_list ( targetList[i] ) ;
    }

    // decide the size of everything
    int     largestValueOfSourceArray       = max ( sourceArray , sizeOfSourceArray ) ;
    int     largestRadixNumberOfSourceArray = radixNumber ( largestValueOfSourceArray ) ;
    int     currRadixNum                    = 0 ;

    #define segment_debug
    #ifdef segment_debug
        printf("before everything\n") ;
    #endif

    for ( i = 0 ; i < sizeOfSourceArray ; i ++ ) {
       
       currRadixNum = sourceArray[i] / power ( 10 , largestRadixNumberOfSourceArray - 1) ;
        // #define radix_debug
        #ifdef radix_debug
            printf ( "currRadixNum %d \t " , currRadixNum ) ;
            printf ( "denominator %d \n " , power ( 10 , largestRadixNumberOfSourceArray - 1) ) ;
        #endif

        #ifdef segment_debug
            printf("before find the insertion point\n") ;
        #endif
       
       for ( currNode = targetList[currRadixNum] ; (currNode->nextNode != NULL); 
                currNode = currNode->nextNode ) 
            if ( sourceArray[i] < currNode->nextNode->value )
                break ;

       #define currNode_debug
       #ifdef currNode_debug
           printf ( "List Num %d, value for insertion %d \t " , currRadixNum , sourceArray[i] ) ;
           printf ( "currNode->nextNode value %d \n " , currNode->value ) ;
       #endif
     
       #ifdef segment_debug
            printf("before insertion\n");
       #endif
       
       // create a new node for insertion 
       node* newNode    = new node ; 
       newNode->value   = sourceArray[i] ;
        
       // insert the node
       insert_node ( currNode , newNode ) ;

    }
    
    // This may leads to segment fault, do not debug with this
    // #define pre_cat_debug
    #ifdef pre_cat_debug
    for ( i = 0 ; i < (sizeOfSourceArray - 1) ; i ++ ) {
        for ( currNode = targetList[i]->nextNode ; currNode->nextNode != NULL ; 
                currNode = currNode->nextNode )     
            printf ( " %dth linked lists leads %d \n " , i, currNode->value ) ;
    }
    #endif
    // may leads to segment fault

    for ( i = 0 ; i < (sizeOfSourceArray - 1) ; i ++ ) {
        #define cancatenation_debug
        #ifdef cancatenation_debug
            printf ( " %dth linked lists leads %d \n " , i, targetList[i]->nextNode->value ) ;
        #endif
        link_linked_lists ( targetList[i]->nextNode , targetList[i + 1] ) ;
    }

    for ( i = 0 , currNode = targetList[0] ; currNode->nextNode != NULL ; 
        currNode = currNode->nextNode , i++ )
        sourceArray[i] = currNode->value ;


    // concatenation has not been done
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

 
