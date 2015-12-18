
#ifndef STACK_H
#define STACK_H

template<class V> class Stack {
	private:
		// stack start pointer, used as a reference pointer
		V*		startPointer ;
		// stack dynamic pointer, used as an end pointer
		V*		stackPointer ;
		// some temporary pointer
		V* 		tmpPointer ;
		// stack size
		int		size ;
		// the memory that has already been allocated for the stack
		int		alloc_size ;
	public:
		Stack () ;
		~Stack () ;
		void push (V value) ;
		V pop () ;
		int stackSize () ;
};

#endif

