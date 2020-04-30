#include<stdio.h>
#include<stdlib.h>
#include "myHeader.h"
  
void selectionSort(int *arr, int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++)  
    {
        for (j = i+1; j < n; j++)  
        	if (arr[j] < arr[i]){
            	int temp=arr[i];
            	arr[i]=arr[j];
            	arr[j]=temp;
  			}
    }  
}

int main(){
	int testcases;
	while(1){
		// int testcases;
		scanf("%d", &testcases);
		if(testcases < 1 || testcases > 10000){
			continue;
		}
		else
			break;
	}
	int coaches;
	while(testcases--){
		scanf("%d", &coaches);
		if(coaches < 1 || coaches > 1000000){
			testcases+=1;
			continue;
		}
		int i=0, rem;
		int arr[10];
		while(1){
			arr[i++] = coaches % 10;
			coaches = coaches/10;
			if(coaches == 0)
				break;
		} //fails when input starts with 0
		print(arr, i);
		selectionSort(arr, i);
		print(arr, i);
		int flag=0;
		for(int j=0; j<i-1; j++){
			if(arr[j]-arr[j+1] != -1)
				flag = 1;
		}
		if(flag==0)
			printf("YES\n");
		else
			printf("NO\n");
	}
}