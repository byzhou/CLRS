// This is a library of linked list

class node {
    public:
        int     value ;
        node*   nextNode ;

    node () ;
    node ( int newValue ) ;
    node ( node* ) ;

};

node::node () {
    value       = -32767 ;
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

class linked_list {
    public:
        node*   lead ;

    linked_list () ;
    ~linked_list () ;
    void addNode ( node addedNode ) ;

};

linked_list::linked_list () {
}

linked_list::~linked_list () {

    node*   currNode ; 
    node*   tmpNode ;

    for ( currNode = lead ; currNode->nextNode != NULL ; 
            currNode = currNode->nextNode ) {

        tmpNode             = currNode ;
        currNode->nextNode  = currNode->nextNode->nextNode ;
        delete tmpNode ;

    }
        
}

void linked_list::addNode ( node addedNode ) {

    node* newNode  = new node ( addedNode ) ;

    node* currNode ; 

    for ( currNode = lead ; currNode->nextNode != NULL ; 
            currNode = currNode->nextNode ) ;

    currNode->nextNode = newNode ;

}



