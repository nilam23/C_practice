#include<stdio.h>

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
		i=0;
		while(i>=0){
			if(arr[i]<K && i<SIZE){
				for(int j=0; j<SIZE; j++){
					arr[j]+=1;
				}
				time++;
				continue;
			}
			if(i!=SIZE)
				i++;
			else
				break;
		}
		printf("%d\n", time);
	}
	return 0;
}