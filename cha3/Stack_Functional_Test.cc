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
			//printf ( "i value is %d\n" , i ) ;
			printf ( "Real stack size is %d\n", stack.stackSize() ) ;
		}
	}
	i--;
	// pop size checker
	printf ( "Pop Process\n" ) ;
	for ( ; i >= 0 ; i -- ) {
		printf ( "i value is %d\n" , i ) ;
		int popvalue = stack.pop() ;
		printf ( "pop success\n" ) ;
		if ( i != popvalue || i != ( stack.stackSize() + 1 ) ) {
			//cerr << "stack size is wrong in pop" << endl ;
			printf ( "popvalue value is %d\n" , popvalue ) ;
			//printf ( "Real stack size is %d\n", stack.stackSize() ) ;
		}
	}
	 //stack.pop() ;
}

