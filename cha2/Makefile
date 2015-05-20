all:run

merge_sort.o:
	~/colorg++ -c merge_sort.cpp 

arrayGen.o:
	~/colorg++ -c arrayGen.cpp

main.o: main.cpp
	~/colorg++ -c main.cpp

main: main.o arrayGen.o
	~/colorg++ main.o arrayGen.o -o main

merge_sort: merge_sort.o arrayGen.o
	~/colorg++ merge_sort.o arrayGen.o -o merge_sort

run: main
	./main

clean:
	rm -rf *.o main merge_sort
