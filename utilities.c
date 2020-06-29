#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "header.h"


void displayTextArt(){

  printf("\n\n");
  printf("     _    _                                ____      _      \n");
  printf("    | |  | |                     ___      |  _ \\    | |    \n");
  printf("    | |__| | ___  __ _ _ __     ( _ )     | |_) |___| |_   \n");
  printf("    |  __  |/ _ \\/ _` | '_ \\    / _ \\/\\   |  _ </ __| __|  \n");
  printf("    | |  | |  __/ (_| | |_) |  | (_>  <   | |_) \\__ \\ |_   \n");
  printf("    |_|  |_|\\___|\\__,_| .__/    \\___/\\/   |____/|___/\\__|  \n");
  printf("                      | |                                  \n");
  printf("                      |_|                                  \n");
  printf("\n\n");


}

int inputCheck(){

    char a[50];
    int i,N,check=0;

    printf("->Give number of elements [number > 2]: ");


    do{
        scanf("%s",a);
        for(i=0; i<strlen(a); i++){

            if(isspace(a[i])){
                check=1;
                break;
            }else if(isdigit(a[i]))
                check=0;
            else if(ispunct(a[i])){
                check=1;
                break;
            }else{
                check=1;
                break;
            }
        }
        if(atoi(a) <= 2)
            check=1;

        if(check ==1){
            char c;
            do{
                c = getchar();
            }while (c != '\n' && c != EOF && c != '\r' );
            printf("->Give again number of elements : ");
        }
    }while(check == 1);

    N=atoi(a);

    return N;
}

double randomGenerator (double min, double max){
    return min + (double) (rand() / (double) (RAND_MAX) * (max - min + 1));
}

void swap(double *A,double *B){

    double temp = *A;
    *A=*B;
    *B=temp;
	return;
}

int isFoundAgain(double num,int N,double *heap){
    int i;
	for(i=0; i<N; i++){

		if(heap[i] == num)
			return 1;
	}

	return 0;
}
