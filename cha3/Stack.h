
#ifndef STACK_H
#define STACK_H

template<class V> class Stack {
	private:
		// stack start pointer, used as a reference pointer
		V*		startPointer ;
		// stack dynamic pointer, used as an end pointer
		V*		stackPointer ;
		// stack size
		int		size ;
	public:
		Stack () ;
		~Stack () ;
		void push (V value) ;
		V pop () ;
		int stackSize () ;
};

#endif

