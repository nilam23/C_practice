#include<stdio.h>
#define MAX 100000
int killSoldiers(int *arr, int size, int power){
	int low=0;
	int up=size-1;
	while(low<=up){
		int mid=(low+up)/2;
		if(power==arr[mid])
			return mid;
		else if(power<arr[mid])
			up=mid-1;
		else
			low=mid+1;
	}
	return -1;
}
int main(){
	int size, arr[MAX], i=0;
	scanf("%d", &size);
	while(i<size && scanf("%d", &arr[i++])==1);
	int rounds;
	scanf("%d", &rounds);
	while(rounds--){
		int power;
		scanf("%d", &power);
		int sum=0;
		int res=killSoldiers(arr, size, power);
		if(power<arr[0]){
			printf("%d %d\n", arr[0], sum);
			break;
		}
		else if(res>=0){
			i=0;
			while(i<=res)
				sum+=arr[i++];
			printf("%d %d\n", power, sum);
		}
		else{
			i=0;
			while(i<size)
				sum+=arr[i++];
			printf("%d %d\n", arr[size-1], sum);
		}
	}
	return 0;
}