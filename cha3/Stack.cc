#include "Stack.h"
// This is for memcpy
#include <string.h> 
#include <new>
#include <stdio.h>
#include <errno.h>
// page size is size of newly allocated memory. Once the memory is running out
// of memory, the stack will automatically adjust its self and allocate another
// page size memory
#define page_size 100

template<class V> Stack<V>::Stack () {
	// size initialization
	size = 0 ;
	// stack pointer initialization start with a size of 100
	try {
		stackPointer = new V[100] ;
	} catch (std::bad_alloc& exc) {
		return ;
	}
        printf ( "pagesize %d\n", page_size );
        printf ( "size of startPointer %lu\n", sizeof ( startPointer ) / sizeof (V) ) ;
	startPointer = stackPointer ;
}

template<class V> Stack<V>::~Stack () {
	delete startPointer ;
}

template<class V> void Stack<V>::push (V value) {
	// given size
	int provided_size = sizeof ( startPointer ) / sizeof ( V ) ;
	// if current size is not enough
	if ( ( size + 1 ) > provided_size ) {
		// resizing stack memory
		try {
			V* tmpPointer = new V[size + page_size] ;
			memcpy ( tmpPointer, startPointer, size ) ;
			delete startPointer ;
			startPointer = tmpPointer ;
		} catch (std::bad_alloc& exc) {
			return ;
		}
		// free the original memory
		stackPointer = startPointer + size ;
	}
	// size increase
	size ++ ;
	// increase the top of stack
	stackPointer ++ ;
	// add value to it
	*stackPointer = value ;
    //printf ( "pushed value %d\n", *(int*)stackPointer ) ;
    printf ( "size of the startPointer %d\n", provided_size ) ;
}

template<class V> V Stack<V>::pop () {
	if ( size == 0 ) {
		perror ( "Stack fault: There is no elements in the stack to pop.\n" ) ;
		return 0;
	} else {
		V returnValue = startPointer[size - 1] ;
		// test if we can shrink the size of stack
		if ((size - 1) % page_size == 0) {
			try {
				V* tmpPointer = new V[size - 1] ;
				memcpy ( tmpPointer, startPointer, size - 1 ) ;
				delete startPointer ;
				startPointer = tmpPointer ;
			} catch (std::bad_alloc& exc) {
				return 0 ;
			}
			size -- ;
			stackPointer = startPointer + size ;
			return returnValue ;
		}
		// decrease the stack depth
		stackPointer-- ;
		// decrease stack size 
		size -- ;
		// give the return value
		return *stackPointer ;
		// the stack pointer pointed value is invalid, next push will over write it
	}
}

template<class V> int Stack<V>::stackSize () {
	return size ;
}
