#include<stdio.h>
#include<string.h>
#include<stdlib.h>
  
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
		scanf("%d", &testcases);
		if(testcases < 1 || testcases > 10000){
			continue;
		}
		else
			break;
	}
	char strCoaches[1000000];
	while(testcases--){
		scanf("%s", strCoaches);
		int i=0;
		int len=strlen(strCoaches);
		int arr[10];
		for(i=0; i<len; i++)
			arr[i]=strCoaches[i]-'0';
		selectionSort(arr, i);
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