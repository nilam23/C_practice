#include<iostream>
#define min(a, b) (a < b ? a : b)
using namespace std;
int gcd(int a, int b){
	for(int i = min(a, b); i > 0; i--){
		if(a % i == 0 && b % i == 0)
			return i;
	}
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