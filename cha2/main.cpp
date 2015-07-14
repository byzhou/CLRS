#include <stdio.h>
#include <stdlib.h>

#include "arrayGen.h"
#include "linked_list.h"

int main () {
    node newNode(10) ;
    linked_list mylist ;

    mylist.addNode(&newNode) ;
    mylist.printLinkedList () ;
    mylist.deleteNextNode(mylist.lead) ;
    mylist.printLinkedList () ;
    //mylist.addNode(newNode) ;

}
