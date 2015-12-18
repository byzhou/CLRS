#include "Stack.h"
// This is for memcpy
#include <string.h> 
#include <new>
#include <stdio.h>
#include <errno.h>
// page size is size of newly allocated memory. Once the memory is running out
// of memory, the stack will automatically adjust its self and allocate another
// page size memory
#define page_size 10

template<class V> Stack<V>::Stack () {
	// size initialization
	size = 0 ;
	// stack pointer initialization start with a size of 100
	try {
		startPointer = new V[page_size] ;
	} catch (std::bad_alloc& exc) {
		return ;
	}
	stackPointer	= startPointer ;
	alloc_size		= page_size ;
}

template<class V> Stack<V>::~Stack () {
	delete[] startPointer ;
	delete[] tmpPointer ;
}

template<class V> void Stack<V>::push (V value) {
	// if current size is not enough
	if ( ( size + 1 ) > alloc_size ) {
		printf ( "we try to allocate some more\n") ;
		// resizing stack memory
		try {
			printf ( "1\n" ) ;
			tmpPointer = new V[alloc_size + page_size] ;
			printf ( "2\n" ) ;
			memcpy ( tmpPointer, startPointer, size ) ;
			printf ( "3\n" ) ;
			alloc_size		+= page_size ;
			printf ( "4\n" ) ;
			delete[] startPointer ;
			printf ( "5\n" ) ;
			startPointer = tmpPointer ;
			printf ( "6\n" ) ;
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
	printf ( "change the stack pointer value to %d\n", value ) ;
	*stackPointer = value ;
	printf ( "This push process stopped.\n" ) ;
}

template<class V> V Stack<V>::pop () {
	if ( size == 0 ) {
		perror ( "Stack fault: There is no elements in the stack to pop.\n" ) ;
		return 0;
	} else {
		V returnValue = startPointer[size] ;
		// test if we can shrink the size of stack
		if ((size + 1) % page_size == 0) {
			try {
				tmpPointer 		= new V[alloc_size - page_size] ;
				alloc_size 		-= page_size ;
				memcpy ( tmpPointer, startPointer, size ) ;
				delete[] startPointer ;
				startPointer = tmpPointer ;
			} catch (std::bad_alloc& exc) {
				return 0 ;
			}
			stackPointer = startPointer + size + 1;
		}
		// decrease the stack depth
		stackPointer-- ;
		// decrease stack size 
		size -- ;
		// give the return value
		return returnValue ;
		// the stack pointer pointed value is invalid, next push will over write it
	}
}

template<class V> int Stack<V>::stackSize () {
	return size ;
}
