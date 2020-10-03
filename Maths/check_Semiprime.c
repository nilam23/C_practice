#include<stdio.h>
#include<math.h>

int isPrime(int n){
	for(int i = 2; i <= sqrt(n); i++){
		if(n%i == 0)
			return 0;
	}
	return 1;
}

int main(){
	int n;
	printf("Enter an integer: ");
	scanf("%d", &n);
	for(int i = 2; i <= n; i++){
		if(isPrime(i)){
			int rem = n % i;
			if(!rem){
				int div = n / i;
				if(isPrime(div)){
					printf("SEMI-PRIME.\n");
					return 0;
				}
			}
		}
	}
	printf("NOT SEMI-PRIME.\n");
	return 0;
}