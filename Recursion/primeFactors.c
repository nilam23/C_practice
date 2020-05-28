#include<stdio.h>
void primeFactors(int num){
	if(num == 1)
		return;
	int i = 2;
	while(num % i != 0)
		i++;
	printf("%d ", i);
	primeFactors(num/i);
}
int main(){
	int num;
	printf("Enter an integer: ");
	scanf("%d", &num);
	printf("The prime factors of %d are: ", num);
	primeFactors(num);
	return 0;
}