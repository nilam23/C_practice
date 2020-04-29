#include<stdio.h>
#include<stdlib.h>
#include "myHeader.h"
#define size 5

void reverseArray(int *arr, int start, int end){
	int temp;
	while(start < end){
		temp = arr[start];
		arr[start] = arr[end];
		arr[end] =temp;
		start++;
		end--;
	}
}

int main(){
	int *arr, i, start, end;
	arr=(int *)malloc(size*sizeof(int));
	if(arr==NULL){
		printf("ERROR:Insufficient space in the heap.\n");
		exit(1);
	}

	getArray(arr, size);
	print(arr, size);
	start = 0;
	end = size-1;
	reverseArray(arr, start, end);
	print(arr, size);
	printf("\n--END--\n");
	return 0;
}