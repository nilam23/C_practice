#include<stdio.h>
#include<stdlib.h>
#include "myHeader.h"

void updateArray(int *arr, int size, int steps){
	int i, j=0;
	while(j<steps){
		for(i=0; i<size-1; i++){
			arr[i]=arr[i+1];
		}
		j++;
	}
}

void merge(int *a, int *b, int lenA, int lenB, int flag){
	int c[10], i=0, j=0, k=0;
	while(i+j < lenA+lenB){
		if(i == lenA){
			c[k++]=b[j++];
		}
		else if(j == lenB){
			c[k++]=a[i++];
		}
		else{
			while(i<(lenA)){
				c[k++]=a[i++];
			}

		}
	}
	printf("\n--After splitting the array at the position %d--\n", flag);
	print(c,k);
	printf("\n--END--");
}

int main(){
	int *arr, *temp, i, pos, j=0, choice, SIZE;
	printf("Enter the size of the array: ");
	scanf("%d", &SIZE);
	arr = (int *)malloc(SIZE * sizeof(int));
	if(arr == NULL){
		printf("Insufficient space for the original array in the heap.\n");
		exit(1);
	}
	temp = (int *)malloc(SIZE * sizeof(int));
	if(temp == NULL){
		printf("Insufficient space for the temp array in the heap.\n");
		exit(1);
	}

	getArray(arr, SIZE);
	print(arr, SIZE);

	while(1){
		printf("\nEnter the index where the array needs to be split: ");
		scanf("%d", &pos);

		if(pos>SIZE){
			printf("ERROR:Position is out of index.\n");
			printf("Do you want to re-enter? Press 0(NO)/1(YES).");
			scanf("%d", &choice);
			if(choice == 1)
				continue;
			else
				break;
		}
		else{
			for(i=0; i<pos; i++){
				 temp[j++]=*(arr+i);
			}
			break;
		}
	}
	updateArray(arr, SIZE, j);
	int sizeTemp=pos;
	temp=(int *)realloc(temp, sizeTemp*sizeof(int));
	int sizeArr=SIZE-pos;
	arr=(int *)realloc(arr, sizeArr*sizeof(int));
	merge(arr, temp, sizeArr, sizeTemp, pos);
	free(arr);
	free(temp);
	return 0;
}
