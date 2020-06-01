#include<iostream>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
using namespace std;
int gcd(int a, int b){
	if(a < b){
		a = a + b;
		b = a - b;
		a = a - b;
	}
	if(a % b == 0)
		return b;
	else
		return gcd(max(b, a-b), min(b, a-b));
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