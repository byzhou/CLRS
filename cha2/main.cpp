#include <stdio.h>
#include <stdlib.h>

#include "arrayGen.h"
#include "linked_list.h"

int main () {
    linked_list mylist ;

    mylist.addNode(10) ;
    mylist.addNode(20) ;
    mylist.addNode(30) ;
    mylist.addNode(30) ;
    mylist.addNode(40) ;
    mylist.addNode(50) ;
    mylist.addNode(60) ;
    mylist.printLinkedList () ;
    mylist.reverseList () ;
    mylist.printLinkedList () ;
    //mylist.addNode(newNode) ;

}
