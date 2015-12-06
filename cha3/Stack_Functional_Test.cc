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
	printf ( "Push Process\n" ) ;
	for ( ; i < 10 ; i ++ ) {
		stack.push (i) ;
		if ( stack.stackSize() != i ) {
			cerr << "stack size is wrong in push" << endl ;
			printf ( "i value is %d\n" , i ) ;
			printf ( "Real stack size is %d\n", stack.stackSize() ) ;
		}
	}

	// pop size checker
	printf ( "Pop Process\n" ) ;
	for ( ; i >= 1 ; i -- ) {
		int popvalue = stack.pop() ;
		if ( i != stack.pop () || i != ( stack.stackSize() + 1 ) ) {
			cerr << "stack size is wrong in pop" << endl ;
			printf ( "i value is %d\n" , i ) ;
			printf ( "popvalue value is %d\n" , popvalue ) ;
			printf ( "Real stack size is %d\n", stack.stackSize() ) ;
		}
	}

	 stack.pop() ;
}

