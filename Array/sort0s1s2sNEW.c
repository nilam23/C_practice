#include<stdio.h>
#include "myHeader.h"
#define MAX 10000
void sort(int *arr, int size){
	int count0=0, count1=0, count2=0;
	for(int i=0; i<size; i++){
		if(arr[i]==0)
			count0++;
		else if(arr[i]==1)
			count1++;
		else
			count2++;
	}
	int i=0;
	while(count0--)
		arr[i++]=0;
	while(count1--)
		arr[i++]=1;
	while(count2--)
		arr[i++]=2;
	return ;
}
int main(){
	int n, arr[MAX], i=0;
	scanf("%d", &n);
	while(i<n && scanf("%d", &arr[i++])==1);
	sort(arr, n);
	print(arr, n);
	return 0;
}