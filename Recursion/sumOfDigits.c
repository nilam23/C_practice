#include<stdio.h>
int sumOfDigits(int n){
	if(n/10 == 0){
		printf("%d + ", n);
		return n;
	}
	else{
		int rem = n%10;
		int sum = (rem + sumOfDigits(n/10));
		printf("%d + ", rem);
		return sum;
	}
}
int main(){
	int n;
	printf("Enter the integer: ");
	scanf("%d", &n);
	printf("The sum of digits of %d:\n", n);
	int res = sumOfDigits(n);
	printf("\b\b= %d\n", res);
	return 0;
}