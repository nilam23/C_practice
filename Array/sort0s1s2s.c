#include<stdio.h>
#include "myHeader.h"
#define MAX 10000
void swap(int *a, int *b){
	int t=*a;
	*a=*b;
	*b=t;
}
void sort(int *arr, int size){
	for(int i=0; i<size; i++){
		if(arr[i]==1)
			continue;
		else if(arr[i]==0){
			int temp=i;
			while(temp!=0 && arr[--temp]!=0)
				swap(&arr[temp], &arr[temp+1]);
		}
		else if(arr[i]==2){
			int temp=i;
			while(temp!=size-1 && arr[++temp]!=0)
				swap(&arr[temp], &arr[temp-1]);
		}
	}
}
int main(){
    int n, arr[MAX], i=0;
    scanf("%d", &n);
    while(i<n && scanf("%d", &arr[i++])==1);
    sort(arr, n);
    print(arr, n);
    return 0;
}