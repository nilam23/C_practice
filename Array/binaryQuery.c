#include<stdio.h>
#include<stdlib.h>

int main(){
	int *arr, N, Q, query,  one=1, zero=0, i;
	printf("Enter array size and no of queries:\n");
	scanf("%d %d", &N, &Q);
	arr = (int *)malloc(N*sizeof(int));

	printf("Enter array elements (space-separated): ");
	while(i<N && (scanf("%d", &arr[i++]))==1);

	while(Q--){
		int res;
		printf("\nEnter Query:\n0. (0 L r)\n1. (1 X)\n");
		scanf("%d", &query);
		if(query%2==one){
			int X;
			printf("For query 1, enter bit position:\n");
			scanf("%d", &X);
			if(arr[X-1]==0)
				arr[X-1]=1;
			else
				arr[X-1]=0;
		}
		else if(query==zero){
			int L, R;
			printf("For Query 2, enter left and right limit:\n");
			scanf("%d %d", &L, &R);

			if(arr[R-1] == 1){
				printf("ODD\n");
			}
			else
				printf("EVEN\n");
		}
	}

	return 0;
}