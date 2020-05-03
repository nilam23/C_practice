#include<stdio.h>
#define MAX 100

int getIndex(int *arr, int n, int item){
	int index=0;
	for(int i=1; i<=n; i++){
		if(arr[i]==item)
			index=i;
	}
	if(index>0)
		return index;
	else
		return -1;
}

int main(){
	int arr[MAX], N, M;
	int i=1;
	scanf("%d %d", &N, &M);
	while(i<=N && scanf("%d", &arr[i++])==1);
	int index=getIndex(arr, N, M);
	printf("%d\n", index);
	return 0;
}