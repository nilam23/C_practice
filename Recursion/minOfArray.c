#include<stdio.h>
int getMin(int *arr, int size){
	if(size==1)
		return arr[0];
	int m = getMin(arr, size-1);
	if(arr[size-1] < m)
		return arr[size-1];
	else
		return m;
}
int main(){
	int n, arr[100];
	printf("Enter the size: ");
	scanf("%d", &n);
	printf("Enter the array:\n");
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);
	printf("The minimum of the array is: %d\n", getMin(arr, n));
	return 0;
}