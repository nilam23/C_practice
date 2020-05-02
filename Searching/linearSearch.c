#include<stdio.h>
#include<stdlib.h>
#define MAX 50

int linearSearch(int *a, int n, int item){
	int i=0;
	while(i<n && a[i]!=item)
		i++;

	if(i==n)
		return -1;
	else
		return i;
}

int searchWithSentinel(int *a, int n, int item){
	a[n]=item;
	int i=0;
	while(a[i]!=item)
		i++;

	if(i==n)
		return -1;
	else
		return i;
}

int searchWithSortedList(int *a, int n, int item){
	for(int i=0; i<n; i++){
		if(a[i]>item)
			return -1;
		else if(a[i]==item)
			return i;
	}
	return -1;
}

int main(){
	int list[MAX], n, item, i=0;
	printf("Enter no of elements to be in the list: ");
	scanf("%d", &n);
	printf("Enter the list:\n");
	while(i<n && scanf("%d", &list[i++])==1);
	printf("Enter the item to be searched in the list: ");
	scanf("%d", &item);

	//basic linear search
	int index=linearSearch(list, n, item);
	if(index==-1)
		printf("Item not found in the list.\n");
	else
		printf("Item found at the index %d of the list.\n", index);

	//linear search with sentinel value
	index=searchWithSentinel(list, n, item);
	if(index==-1)
		printf("NOT PRESENT\n");
	else
		printf("PRESENT, index=%d.\n", index);

	//linear search in a sorted list(ascending order)
	int sorted[n], newItem;
	printf("Enter a sorted list of %d elements in ascending order:\n", n);
	i=0;
	while(i<n && scanf("%d", &sorted[i++])==1);
	printf("Enter another item to be searched in the sorted list: ");
	scanf("%d", &newItem);
	index=searchWithSortedList(sorted, n, newItem);
	if(index==-1)
		printf("NOT PRESENT\n");
	else
		printf("PRESENT, index=%d.\n", index);
	return 0;
}
