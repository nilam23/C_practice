/* Recursive program to find out
summation of the numbers from 1 to n */

#include<stdio.h>
int sum(int n){
	if(n == 0)
		return 0;
	int res = (n + sum(n-1));
	printf("%d + ", n);
	return res;
}
int main(){
	int n;
	printf("Enter the no of terms: ");
	scanf("%d", &n);
	printf("Summation is:\n");
	int res = sum(n);
	printf("\b\b= %d\n", res);
	return 0;
}