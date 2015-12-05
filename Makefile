FLAGS	:= -Wall -O3
SRCS	:= stack.cpp
TAGETS	:= $(SRCS:%.cpp=%.o)

%.o : %.cpp
	gcc $(FLAGS) $<
all: $(TAGETS)
	./test_code

	
