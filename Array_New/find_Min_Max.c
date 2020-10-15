#include<stdlib.h>
#include<stdio.h>

struct Minmax{
	int min;
	int max;
};

struct Minmax findMinMax1(int *arr, int n){
	struct Minmax pair;
	pair.min = arr[0];
	pair.max = arr[0];
	for(int i = 0; i < n; i++){
		if(arr[i] < pair.min)
			pair.min = arr[i];
		if(arr[i] > pair.max)
			pair.max = arr[i];
	}
	return pair;
}

struct Minmax findMinMax2(int arr[], int l, int r){
	struct Minmax pair, pair1, pair2;
	int mid;
	if(l == r){
		pair.min = arr[l];
		pair.max = arr[l];
		return pair;
	}
	else if(r == l+1){
		if(arr[l] > arr[r]){
			pair.min = arr[r];
			pair.max = arr[l];
		}
		else{
			pair.min = arr[l];
			pair.max = arr[r];
		}
		return pair;
	}
	mid = (l+r)/2;
	pair1 = findMinMax2(arr, l, mid);
	pair2 = findMinMax2(arr, mid+1, r);
	if(pair1.min < pair2.min)
		pair.min = pair1.min;
	else
		pair.min = pair2.min;
	if(pair1.max > pair2.max)
		pair.max = pair1.max;
	else
		pair.max = pair2.max;
	return pair;
}

int main(){
	struct Minmax pair;
	int *arr, size, i=0;
	printf("Enter the size of the array: ");
	scanf("%d", &size);
	arr = (int *)malloc(size * sizeof(int));
	printf("Enter the array elements:\n");
	while(i<size && scanf("%d", &arr[i++])==1);
	pair = findMinMax1(arr, size);
	printf("Minimum element of the array is %d\n", pair.min);
	printf("Maximum element of the array is %d\n", pair.max);
	pair = findMinMax2(arr, 0, size-1);
	printf("Minimum element of the array is %d\n", pair.min);
	printf("Maximum element of the array is %d\n", pair.max);
	return 0;
}