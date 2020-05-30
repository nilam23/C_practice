#include<stdio.h>
int digits(int n){
	if(n == 0)
		return 0;
	return 1 + digits(n/10);
}
int main(){
	int n;
	printf("Enter the no: ");
	scanf("%d", &n);
	printf("Total no of digits in %d is: %d\n", n, digits(n));
	return 0;
}