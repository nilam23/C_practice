#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "myHeader.h"
#define SIZE 5

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void shuffle(int *arr, int size){
	srand(time(0));
	int i, j;
	for(i=size-1; i>0; i--){
		printf("SHF\n");
		j = rand() % (i+1);
		swap(&arr[i], &arr[j]);
	}
	return;
}

int main(){
	int *arr;
	arr=(int *)malloc(SIZE*sizeof(int));
	if(arr==NULL){
		printf("ERROR:Insufficient space in the heap.\n");
		exit(1);
	}

	getArray(arr, SIZE);
	print(arr, SIZE);

	shuffle(arr, SIZE);
	printf("--After shuffling--");
	print(arr, SIZE);
	return 0;
}