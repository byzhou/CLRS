#include "Stack.h"

template<class V> Stack<V>::Stack () {
	// size initialization
	size = 0 ;
	// stack pointer initialization
	stackPointer = startPointer ;
}

template<class V> Stack<V>::~Stack () {
	// scanner pointer
	V* currV ;
	// scanning through the entire stack
	for ( currV = startPointer ; currV != stackPointer ; currV ++ ) 
		delete currV ;
}

template<class V> void Stack<V>::push (V value) {
	// allocate new memory for stack
	stackPointer = new V ;
	// move stack pointer to the next point
	stackPointer++ ;
	// give the value of the v
	*stackPointer = value ;
	// size increase
	size ++ ;
}

template<class V> V Stack<V>::pop () {
	// decrease the stack depth
	stackPointer-- ;
	// save tmp return value 
	V returnValue = *stackPointer ;
	// delete the previous location data
	delete stackPointer ;
	// decrease stack size 
	size -- ;
	// give the return value
	return returnValue ;
}

template<class V> int Stack<V>::stackSize () {
	return size ;
}
