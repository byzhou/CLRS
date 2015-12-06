#include "Stack.h"
#include <new>

template<class V> Stack<V>::Stack () {
	// size initialization
	size = 1 ;
	// stack pointer initialization
	try {
		stackPointer = new V ;
	} catch (std::bad_alloc& exc) {
		return ;
	}
	startPointer = stackPointer ;
}

template<class V> Stack<V>::~Stack () {
	// scanner pointer
	V* currV ;
	// scanning through the entire stack
	for ( currV = startPointer ; currV != stackPointer ; currV ++ ) 
		delete currV ;
	size = 0 ;
}

template<class V> void Stack<V>::push (V value) {
	// give the value of the v
	*stackPointer = value ;
	// move stack pointer to the next point
	stackPointer++ ;
	// allocate new memory for stack
	try {
		stackPointer = new V ;
	} catch (std::bad_alloc& exc){
		return ;
	}
	// size increase
	size ++ ;
}

template<class V> V Stack<V>::pop () {
	// decrease the stack depth
	stackPointer-- ;
	// delete the previous location data
	delete (stackPointer + 1);
	// decrease stack size 
	size -- ;
	// give the return value
	return *stackPointer ;
	// the stack pointer pointed value is invalid, next push will over write it
}

template<class V> int Stack<V>::stackSize () {
	return size ;
}
