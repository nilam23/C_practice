#include<stdio.h>
#include<stdlib.h>
int binarySearch(int *arr, int size, int item){
	int low=0;
	int up=size-1;
	int partition=0;
	while(low<=up){
		int mid=(low+up)/2;
		printf("\nAfter %d partion,\nLOW=%d\tMID=%d\tUP=%d\n", partition, low, mid, up);
		if(arr[mid]==item)
			return 1;
		else if(item<arr[mid])
			up=mid-1;
		else
			low=mid+1;
		partition++;
	}
	return 0;
}
int main(){
	int size,*arr, item, testcases, i=0;
	printf("Enter the size of the array: ");
	scanf("%d", &size);
	arr=(int *)malloc(size*sizeof(int));
	printf("Enter the elements into the array:\n");
	while(i<size && scanf("%d", &arr[i++])==1);
	printf("Enter no of testcases: ");
	scanf("%d", &testcases);
	while(testcases--){
		printf("Enter the item to be searched: ");
		scanf("%d", &item);
		if(binarySearch(arr, size, item))
			printf("PRESENT.\n");
		else
			printf("NOT PRESENT.\n");
	}
	return 0;
}