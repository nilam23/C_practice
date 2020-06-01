#include<iostream>
#define max(a, b) (a > b ? a : b)
using namespace std;
int gcd(int a, int b){
	int result;
	for(int i = 1; i <= max(a, b); i++){
		if(a % i == 0 && b % i == 0)
			result = i;
	}
	return result;
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