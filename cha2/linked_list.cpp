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
    printf ( "destructor worked \n " ) ;
}

void linked_list::addNode ( node* addedNode ) {
    printf ( "adding node\n" ) ;
    node* newNode  = new node ( addedNode->value ) ;
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
    #ifdef _DEBUG_
        printf ( "Printing linked list finished.\n" );
    #endif
}
