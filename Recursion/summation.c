/* Recursive program to find out
summation of the numbers from 1 to n */

#include<stdio.h>
int sum(int n){
	if(n == 0)
		return 0;
	else
		return n + sum(n-1);
}
int main(){
	int n;
	printf("Enter the upper bound: ");
	scanf("%d", &n);
	int res = sum(n);
	printf("Total sum= %d\n", res);
	return 0;
}