#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"


int main(){

    srand(time(NULL));
    int N,check=0,i,t=0,pos=0;
    double *heap=NULL,temp;
    TreeNode *root=NULL;

    displayTextArt();

    N=inputCheck();

    printf("\n");

    // allocate memory for double array of N elements
    heap=(double*)malloc(N*sizeof(double));


    for(i=0; i<N; i++){
		do{
			temp = randomGenerator(0,99);

			check=isFoundAgain(temp,N,heap);

			if(check == 0){
				insertToHeap(temp,i,N,heap);
				root=insertToBinaryTree(root,temp);
			}
		}while(check == 1);

		if(i==0)
			printf("->Input: %.2f ",temp);
        else
			printf("%.2f ",temp);
    }//end of for

    if((N*7) >= 56)
        t=N*8;
    else
        t=60;


    printf("\n");
	printf("\n");
    for(i=0; i<t; i++)
        printf("-");
    printf("\n");
    printf("Process: Delete The Maximum Number Of Heap And Binary Tree\n");
    printf("->Calculating...\n\n");

    for(i=N; i>N/2; i--){

		printf("\n");

        printf("->HeapMax :%.2f\n",maxNumberOfHeap(heap));
        printf("->BstMax  :%.2f\n",printBstMax(root));

		printf("Current Binary Tree Form:\n");
        inorder(root);
        printf("\n");

        // CALL
        root=removeBstd(&root);
        deleteMaxHeap(heap,i,N);
        printf("\n");
    }// end of for

    int countPos=0;
    while(1){

      if (heap[countPos]>=0)
        countPos++;
      else
        break;
    }// end of while

    printf("\n");
    printf("->Done\n");

    for(i=0; i<t; i++)
        printf("-");
    printf("\n");
    printf("Process: Search Random Number In Binary Tree And Rotate\n");
    printf("->Calculating...\n\n");
    printf("\n");

    printf("Current Binary Tree Form:\n");
    inorder(root);
    printf("\n\n");

    if(countPos!=0){
        pos=rand() % countPos;
        printf("Search for Number : %.2f\n",heap[pos]);
        printf("->Number of Comparisons for element <%.2f> = %d\n\n",heap[pos],searchBst(&root,heap[pos]));
    }
    printf("Rotate for Number : %.2f\n",heap[pos]);

    root = isValidRotation(&root,heap[pos]);

    printf("\nFinal Binary Tree Form After Rotation:\n");
    inorder(root);
    printf("\n\n");
    printf("->Done\n");


    for(i=0; i<t; i++)
        printf("-");
    printf("\n");
    printf("Process: Free Binary Tree And Heap\n");
    printf("->Deleting...\n\n");

    // Free heap
    destroyHeap(heap);
    printf("\n->Heap Destroy\n");

    // Free binary Tree
    destroyBst(root);
    printf("->Binary Tree Destroy\n");

    printf("\n\n");
    printf("->Done\n");
    for(i=0; i<t; i++)
        printf("-");
    printf("\n");

    printf("\n->Goodbye!!!\n");
    return 0;
}
