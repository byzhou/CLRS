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
	printf ( "Push Process\n" ) ;
	for ( ; i < 20 ; i ++ ) {
		stack.push (i) ;
		if ( stack.stackSize() != i ) {
			//cerr << "stack size is wrong in push" << endl ;
			printf ( "i value is %d " , i ) ;
			printf ( "stack memory size %d " , stack.stackMemorySize() ) ;
			printf ( "Real stack size is %d\n", stack.stackSize() ) ;
		}
	}
	i--;
	// pop size checker
	printf ( "Pop Process\n" ) ;
	for ( ; i >= 0 ; i -- ) {
		int popvalue = stack.pop() ;
		if ( i != popvalue || i != ( stack.stackSize() + 1 ) ) {
			//cerr << "stack size is wrong in pop" << endl ;
			printf ( "pop_value value is %d " , popvalue ) ;
			printf ( "stack memory size %d " , stack.stackMemorySize() ) ;
			printf ( "Real stack size is %d\n", stack.stackSize() ) ;
		}
	}
}

