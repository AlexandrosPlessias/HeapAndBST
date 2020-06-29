#include <stdio.h>
#include <stdlib.h>
#include "header.h"


void insertToHeap(double key,int currentSize,int N,double *heap){

    if( currentSize > N){
        // NEVER HAPPEN.
        printf("Overflow...\n");
        exit(0);
    }

    heap[currentSize] = key;

    int i = currentSize;

    // p=parent
    int p = (i-1) / 2;

    while ((i > 0) && (heap[i] > heap[p])){

        swap(&heap[i], &heap[p]);
        i = p;
        p = (i-1) / 2;
    }

}

double deleteMaxHeap(double *heap, int currentSize,int N){

    if( currentSize > N){
        printf("Overflow\n");
        return 0;
    }
    double maxKey=heap[0];

    heap[0]=heap[currentSize-1]; // copy the last key to the root

    int i=0, l=1, r=2; // l, r current tree-node children

    while (l < currentSize-1){

        int maxValueChild = l; // maxValueChild : child with the biggest key

        if (r <= currentSize && heap[r] > heap[l])
            maxValueChild=r;

        if (heap[i] >= heap[maxValueChild])
            break;

        swap(&heap[i],&heap[maxValueChild]); // swap values parent - child

        i=maxValueChild;

        l=2*i + 1;

        r=l+1; // the new i and his children
    }

    heap[currentSize-1]=-1;

    return maxKey;
}

void printHeap(int N,double *heap){

    int i;

    printf("\n\n");

    for(i=0; i<N; i++){

        if(heap[i] != -1)
            printf("%.2f ",heap[i]);
    }

    printf("\n\n");

}

double maxNumberOfHeap(double *heap){

    return heap[0];
}

void destroyHeap(double *heap){

    free(heap);
}
