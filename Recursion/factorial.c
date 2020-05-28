#include<stdio.h>

int fact(int n){
	if(n == 0)
		return 1;
	if(n == 1)
		return 1;
	else
		return n * fact(n-1);
}

int main(){
	int n;
	printf("Enter the integer: ");
	scanf("%d", &n);
	int res = fact(n);
	printf("Factorial of %d is %d\n", n, res);
	return 0;
}