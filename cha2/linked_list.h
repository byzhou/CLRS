#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

class node {
    public:
        int     value ;
        node*   nextNode ;

    node () ;
    node ( int newValue ) ;
    node ( node* ) ;
};


class linked_list {
    public:
        node*   lead ;

    linked_list () ;
    ~linked_list () ;
    void printLinkedList () ;
    void addNode ( node* addedNode ) ;

};
    
#endif

