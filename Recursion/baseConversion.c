#include<stdio.h>
void convert(int n, int base){
	int rem = n % base;
	if(n == 0)
		return;
	convert(n/base, base);
	if(rem < 10)
		printf("%d", rem);
	else
		printf("%c", rem - 10 + 'A');
	return;
}
int main(){
	int n, base;
	printf("Enter the decimal no: ");
	scanf("%d", &n);
	printf("Enter base for conversion: ");
	scanf("%d", &base);
	printf("After converting %d to the base %d: ", n, base);
	convert(n, base);
	return 0;
}