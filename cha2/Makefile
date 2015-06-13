
all:run

merge_sort.o: merge_sort.cpp
	~/colorg++ -c merge_sort.cpp 

insert_sort.o: insert_sort.cpp
	~/colorg++ -c insert_sort.cpp 

quick_sort.o: quick_sort.cpp
	g++ -c quick_sort.cpp

heap_sort.o: heap_sort.cpp
	~/colorg++ -c heap_sort.cpp

counting_sort.o: counting_sort.cpp
	g++ -c counting_sort.cpp

radix_sort.o: radix_sort.cpp
	g++ -c radix_sort.cpp

bucket_sort.o: bucket_sort.cpp
	g++ -c bucket_sort.cpp

arrayGen.o: arrayGen.cpp
	g++ -c arrayGen.cpp

quick_sort: quick_sort.o arrayGen.o
	g++ quick_sort.o arrayGen.o -o quick_sort

counting_sort: counting_sort.o arrayGen.o
	g++ counting_sort.o arrayGen.o -o counting_sort 

radix_sort: radix_sort.o arrayGen.o
	g++ radix_sort.o arrayGen.o -o radix_sort

bucket_sort: bucket_sort.o arrayGen.o
	g++ bucket_sort.o arrayGen.o -o bucket_sort

main.o: main.cpp
	~/colorg++ -c main.cpp

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

run_quick_sort: quick_sort
	./quick_sort

run_counting_sort: counting_sort
	./counting_sort

run_radix_sort: radix_sort
	./radix_sort

run_bucket_sort: bucket_sort
	./bucket_sort

run: run_bucket_sort

clean:
	rm -rf *.o main merge_sort insert_sort heap_sort quick_sort
