#include<stdio.h>
#include<stdlib.h>
#include "myHeader.h"
#define SIZE 5
#define bool int

bool pairSum(int *arr, int size, int k){
	int i, j;
	for(i=0; i<size-1; i++){
		for(j=i+1; j<size; j++){
			if(arr[i] + arr[j] == k){
				return 1;
			}
		}
	}
	return 0;
}

int main(){
	int *arr, k;
	arr=(int *)malloc(SIZE * sizeof(int));
	if(arr==NULL){
		printf("ERROR:Insufficient space in the errror.\n");
		exit(1);
	}

	int i=0;
	printf("--Enter space separated array elements--\n");
	while (i<SIZE && scanf("%d", &arr[i++])==1);
	print(arr, SIZE);

	printf("Enter the value of K: ");
	scanf("%d", &k);
	if(pairSum(arr, SIZE, k))
		printf("There exists a pair of numbers that sum to the number %d.\n", k);
	else
		printf("There exists no such pairs.\n");
	free(arr);
	return 0;
}
