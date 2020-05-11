#include<stdio.h>
#include<stdlib.h>
int binarySearch(int *arr, int low, int up, int item){
	int mid=(low+up)/2;
	// printf("\n%d %d %d\n", low, mid, up);
	if(item==arr[mid])
		return 1;
	else if(low>up)
		return 0;
	else if(item<arr[mid]){
		up=mid-1;
		binarySearch(arr, low, up, item);
	}
	else if(item>arr[mid]){
		low=mid+1;
		binarySearch(arr, low, up, item);
	}
}
int main(){
	int testcases;
	printf("Enter no of testcases: ");
	scanf("%d", &testcases);
	int size,*arr, i=0;
	printf("Enter size of array: ");
	scanf("%d", &size);
	arr=(int *)malloc(size*sizeof(int));
	printf("Enter the sorted array:\n");
	while(i<size && scanf("%d", &arr[i++])==1);
	while(testcases--){
		int item;
		printf("Enter the item to be searched: ");
		scanf("%d", &item);
		if(binarySearch(arr, 0, size-1, item))
			printf("PRESENT.\n");
		else
			printf("NOT PRESENT.\n");
	}
	return 0;
}