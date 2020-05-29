#include<stdio.h>
int getMin(int *arr, int low, int high){
	int mid, left, right;
	if(low==high)
		return arr[low];
	mid=(low+high)/2;
	left=getMin(arr, low, mid);
	right=getMin(arr, mid+1, high);
	if(left<right)
		return left;
	else
		return right;
}
int main(){
	int n, arr[100];
	printf("Enter the size: ");
	scanf("%d", &n);
	printf("Enter the array:\n");
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);
	printf("The minimum of the array is: %d\n", getMin(arr, 0, n-1));
	return 0;
}