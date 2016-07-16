#include "Stack.h"
// This is for memcpy
#include <string.h> 
#include <new>
#include <stdio.h>
#include <errno.h>

template<class V> Stack<V>::Stack () {
	// size initialization
	size 					= 0 ;
	allocated_memory_size 	= 0 ;
	// stack pointer initialization start with a size of 100
	try {
		startPointer = new V ;
	} catch (std::bad_alloc& exc) {
		return ;
	}
	stackPointer	= startPointer ;
}

template<class V> Stack<V>::~Stack () {
	//delete[] startPointer ;
	int i ;
	// Since the size of my stack is been expended exponentionally, thus memory
	// needs to be released according to the order and size of the memory that
	// has been initially allocated.
	  
	// for ( i = (allocated_memory_size >> 1); i == 1; i >> 1 ){
	// 	delete[] (startPointer + i);
	// }
	//delete startPointer;
}

template<class V> void Stack<V>::push (V value) {
	V* tmpPointer;
	if ( size == 0 ) {
		try {
			startPointer 			= new V;
			stackPointer			= startPointer ;
			size 					= 1;
			allocated_memory_size 	= 1;
		} catch (std::bad_alloc& exc) {
			return;
		}
	} else if ( (startPointer + allocated_memory_size - 1) == stackPointer ) {
		// allocate more memory to make stack larger 
		// if the size of the stack is not enough, we double the stack size
		try{
			tmpPointer = startPointer + size ;
			tmpPointer = new V[size];	
			stackPointer ++ ;
			*stackPointer = value ;
			size ++;
			allocated_memory_size  = allocated_memory_size * 2 ;
		} catch (std::bad_alloc& exc) {
			return;
		}
	} else {
		stackPointer ++ ;
		*stackPointer = value ;
		size ++;
	}
	return;
}

template<class V> V Stack<V>::pop () {
	
	if (size == 0) {
		perror ( "Stack fault: There is no elements in the stack to pop.\n" ) ;	
	}
	V returnValue = *stackPointer ;
	stackPointer -- ;
	size -- ;
	// if (size < (allocated_memory_size / 2)) {
	// 	delete[] (startPointer + (allocated_memory_size >> 1));
	// 	allocated_memory_size = allocated_memory_size >> 2;
	// }
	return returnValue;

}

template<class V> int Stack<V>::stackSize () {
	return size ;
}

template<class V> int Stack<V>::stackMemorySize () {
	return allocated_memory_size ;
}
