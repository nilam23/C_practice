#include<stdio.h>
int power(int a, int n){
	if(n == 0)
		return 1;
	else
		return a * power(a, n-1);
}
int main(){
	int a, n;
	printf("Enter the integer and it's power: ");
	scanf("%d %d", &a, &n);
	printf("%d raised to the power %d is %d\n", a, n, power(a, n));
	return 0;
}