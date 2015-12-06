# cmake preparation file
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
# project name
project ( "cmake cha3" ) 
enable_testing() 
add_executable (Stack_Basic Stack_Functional_Test.cc Stack.cc)
add_executable (Stack_Advance Stack_Stress_Test.cc Stack.cc)
# test stack
add_test(Stack_Functional_Test Stack_Basic)
add_test(Stack_Stress_Test Stack_Advance)
