
all:run

merge_sort.o:
	~/colorg++ -c merge_sort.cpp 

insert_sort.o:
	~/colorg++ -c insert_sort.cpp 

arrayGen.o:
	~/colorg++ -c arrayGen.cpp

main.o: main.cpp
	~/colorg++ -c main.cpp

heap_sort.o: heap_sort.cpp
	~/colorg++ -c heap_sort.cpp

heap_sort: heap_sort.o arrayGen.o
	~/colorg++ heap_sort.o arrayGen.o -o heap_sort

main: main.o arrayGen.o
	~/colorg++ main.o arrayGen.o -o main

merge_sort: merge_sort.o arrayGen.o
	~/colorg++ merge_sort.o arrayGen.o -o merge_sort

insert_sort: insert_sort.o arrayGen.o
	~/colorg++ insert_sort.o arrayGen.o -o insert_sort

run_main: main
	./main

run_merge_sort: merge_sort
	./merge_sort

run_heap_sort: heap_sort
	./heap_sort

run_insert_sort: insert_sort
	time ./insert_sort

run: run_heap_sort

clean:
	rm -rf *.o main merge_sort insert_sort heap_sort
