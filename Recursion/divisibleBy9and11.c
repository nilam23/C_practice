#include<stdio.h>
int divisibleBy9(int num){
	if(num == 9)
		return 1;
	if(num < 9)
		return 0;
	int sum = 0;
	while(num > 0){
		sum += (num%10);
		num /= 10;
	}
	divisibleBy9(sum);
}
int divisibleBy11(int num){
	if(num == 0 || num%11 == 0)
		return 1;
	if(num < 11)
		return 0;
	int s1 = 0, s2 = 0;
	while(num > 0){
		s1 += (num%10);
		num /= 10;
		s2 += (num%10);
		num /= 10;
	}
	int diff = s1>s2 ? (s1-s2) : (s2-s1);
	divisibleBy11(diff);
}
int main(){
	int num;
	printf("Enter the integer: ");
	scanf("%d", &num);
	int check1 = divisibleBy9(num);
	if(check1 == 0)
		printf("Not divisible by 9.\n");
	else
		printf("Divisible by 9.\n");
	int check2 = divisibleBy11(num);
	if(check2 == 0)
		printf("Not divisible by 11.\n");
	else
		printf("Divisible by 11.\n");
	return 0;
}

/*Note 1: A no is divisible by 9 iff the sum of digits of the number is divisible by 9.*/

/*Note 2: A no is divisible by 11 iff the difference between the sum of digits at the odd positions
and the sum of digitis at the even positions is either 0 or divisible by 11.*/