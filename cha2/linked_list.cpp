// This is a library of linked list
#ifndef librarys
#define librarys
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#endif
#include "linked_list.h"

#define _DEBUG_
node::node () {
    value       = 0 ;
    nextNode    = NULL ;
}

node::node ( int newValue ) {
    value       = newValue ; 
    nextNode    = NULL ;
}

node::node ( node* newNode ) {
    value       = newNode->value ;
    nextNode    = newNode->nextNode ;
}

linked_list::linked_list () {
    lead        = new node ;
    printf ( "linked_list created\n" ) ;
}

linked_list::~linked_list () {
    node*   currNode ; 
    node*   tmpNode ;
    for ( currNode = lead ; currNode->nextNode != NULL ; currNode = currNode->nextNode ) {
        tmpNode             = currNode ;
        delete tmpNode ;
    }
    #ifdef _DEBUG_
        printf ( "destructor worked \n " ) ;
    #endif
}

void linked_list::addNode ( node* addedNode ) {
    #ifdef _DEBUG_
        printf ( "adding node\n" ) ;
    #endif
    node* newNode   = new node ( addedNode->value ) ;
    node* currNode ; 
    for ( currNode = lead ; currNode->nextNode != NULL ; currNode = currNode->nextNode ) ;
    currNode->nextNode = newNode ;
}

void linked_list::addNode ( int nodeValue ) {
    node* newNode   = new node ( nodeValue ) ;
    node* currNode ; 
    for ( currNode = lead ; currNode->nextNode != NULL ; currNode = currNode->nextNode ) ;
    currNode->nextNode = newNode ;
}

void linked_list::printLinkedList () {
    #ifdef _DEBUG_
        printf ( "start printing the linked list.\n" );
    #endif
    node* currNode ; 
    for ( currNode = lead ; currNode->nextNode != NULL ; currNode = currNode->nextNode ) {
        printf ( " %d \n" , currNode->value ) ;
    }
        printf ( " %d \n" , currNode->value ) ;
    #ifdef _DEBUG_
        printf ( "Printing linked list finished.\n" );
    #endif
}

void linked_list::deleteNextNode ( node* thisNode ) {
    
    node* tmpNode ;

    if ( thisNode->nextNode == NULL ) 
        printf ( "next node is NULL \n" ) ;
    else {
        tmpNode             = thisNode->nextNode ;
        thisNode->nextNode  = thisNode->nextNode->nextNode ;
        delete tmpNode ;
    }

    #ifdef _DEBUG_
        printf ( "node is deleted. \n" ) ;
    #endif

}

node* linked_list::searchNode ( int value ) {
    node* currNode ;
    for ( currNode = lead ; currNode->nextNode != NULL ; currNode = currNode->nextNode ) {
        if ( currNode->value == value ) 
            return currNode ;
    }
    return NULL ;
}

void linked_list::reverseList () {
    node* nextNextCurrNode, nextCurrNode , currNode ;

    currNode            = lead ;
    nextCurrNode        = lead->nextNode ;

    // if nextCurrNode does not exist
    if ( nextCurrNode == NULL ) 
        return 0 ;
    else if ( nextCurrNode->nextNode == NULL )
        // if nextNextCurrNode does not exist
        nextCurrNode->nextNode  = lead ;
        lead->nextNode          = NULL ;
        return 0 ;
    } else {
        // if three nodes do exist
        nextNextCurrNode        = nextCurrNode->nextNode ;
    }

    // till this point, three dynamic pointer must not be NULL
    for ( ; nextNextCurrNode != NULL ;){
        // reverse
        nextCurrNode->nextNode  = currNode ;
        if ( nextNextCurrNode->nextNode == NULL ) {
            // if there is no next step, finish reversing this cycle
            nextNextCurrNode->nextNode = nextCurrNode ;
            return 0 ;
        } else {
            currNode            = nextCurrNode ;
            nextCurrNode        = nextNextCurrNode ;
            nextNextCurrNode    = nextNextCurrNode -> nextNode ;
        }
    }


}
