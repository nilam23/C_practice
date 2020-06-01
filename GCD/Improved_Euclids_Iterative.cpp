#include<iostream>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
using namespace std;
int gcd(int a, int b){
	int rem;
	if(a < b){
		a = a + b;
		b = a - b;
		a = a - b;
	}
	while(a % b != 0){
		rem = a % b;
		a = b;
		b = rem;
	}
	return b;
}
int main(){
	int a, b;
	cout << "Enter the first integer: ";
	cin >> a;
	cout << "Enter the second integer: ";
	cin >> b;
	cout << "GCD of " << a << " and " << b << " is: " << gcd(a, b);
	return 0;
}