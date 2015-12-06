# cmake preparation file
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
# project name
project ( "cmake cha3" ) 
enable_testing() 
add_executable (Stack Stack_test.cc Stack.cc)
# test stack
add_test(stackTest Stack)
