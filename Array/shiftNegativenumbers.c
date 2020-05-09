#include<stdio.h>
#include "myHeader.h"
#define MAX 1000
void swap(int *a, int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
void shift(int *arr, int size){
	for(int i=0; i<size; i++){
		if(arr[i]>=0)
			continue;
		else{
			int temp=i;
			while(arr[--temp]>0)
				swap(&arr[temp], &arr[temp+1]);
		}
	}
	return ;
}
int main(){
	int n, arr[MAX], i=0;
	printf("Enter the size of the array: ");
	scanf("%d", &n);
	printf("Enter the space separated array elements:\n");
	while(i<n && scanf("%d", &arr[i++])==1);
	shift(arr, n);
	print(arr, n);
	return 0;
}