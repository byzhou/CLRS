#include <iostream>
#include <stdio.h>
	using std::cerr;
	using std::endl;
#include "Stack.h"
#include "Stack.cc"

int main ( int argc, char** argv ) {
	
	 Stack<int> stack ;

	 // push size checker
	int i = 1 ;
	for ( ; i < 10000 ; i ++ ) {
		stack.push (i) ;
		if ( stack.stackSize() != i ) {
			cerr << "stack size is wrong in push" << endl ;
		}
	}

	 // pop size checker
	 for ( ; i >= 1 ; i -- ) {
	 	if ( i != stack.pop () || i != ( stack.stackSize() + 1 ) ) 
			cerr << "stack size is wrong in pop" << endl ;
	 }
}

