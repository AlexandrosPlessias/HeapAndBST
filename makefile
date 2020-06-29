HeapAndBst: main.o utilities.o heap.o bst.o
	gcc -o HeapAndBst main.o utilities.o heap.o bst.o

main.o: header.h main.c
	gcc -c main.c

utilities.o: utilities.c
	gcc -c utilities.c
	
heap.o: heap.c
	gcc -c heap.c
	
bst.o: bst.c
	gcc -c bst.c	