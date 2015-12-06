#include <iostream>
#include <stdio.h>
	using std::cerr;
	using std::endl;
#include "Stack.h"
#include "Stack.cc"

int main ( int argc, char** argv ) {
	
	Stack<int> stack ;

	// push size checker
	int i = 0 ;
	for (  ; i < 10 ; i ++ ) {
		printf ("number of line crush %d\n", i ) ;
		stack.push ( i ) ;
	}
		printf ("number of line crush %d\n", i ) ;

	//if ( stack.stackSize() != 10 ) {
	//	cerr << "stack size is wrong" << endl ;
	//}

	return 0 ;
}

