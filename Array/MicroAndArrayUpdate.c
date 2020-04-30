#include<stdio.h>
#define getMin(a, b) (a < b ? a : b)
#define getMax(a, b) (a > b ? a : b)

int main(){
	int testCases;
	scanf("%d", &testCases);
	while(testCases--){
		int SIZE, K;
		scanf("%d %d", &SIZE, &K);
		int arr[SIZE], i=0;
		while(i<SIZE && (scanf("%d", (arr+i)))==1)
			i++;

		int time=0;
		int min=1e9;
		i=0;
		while(i<SIZE){
			min=getMin(min,arr[i]);
			i++;
		}
		time=getMax(0, K-min);
		printf("%d\n", time);
	}
	return 0;
}