#include<stdio.h>
#define MAX 10000
void getMinMax(int *arr, int size, int *min, int *max){
	*min=arr[0];
	*max=arr[0];
	for(int i=0; i<size; i++){
		if(arr[i]<*min)
			*min=arr[i];
		if(arr[i]>*max)
			*max=arr[i];
	}
}
int main(){
	int n, arr[MAX], i=0;
	scanf("%d", &n);
	while(i<n && scanf("%d", &arr[i++])==1);
	int min, max;
	getMinMax(arr, n, &min, &max);
	printf("Range: %d\n", (max-min));
	return 0;
}