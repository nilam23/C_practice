#include<iostream>
using namespace std;
int getGcd(int a, int b){
	if(a < b){
		a = a + b;
		b = a - b;
		a = a - b;
	}
	if(b == 0)
		return a;
	else
		return getGcd(a % b, b);
}
int getLcm(int a, int b){
	return (a * b)/getGcd(a, b);
}
int main(){
	int a, b, lcm;
	cout << "Enter the first integer: ";
	cin >> a;
	cout << "Enter the second integer: ";
	cin >> b;
	lcm = getLcm(a, b);
	cout << "LCM of " << a << " and " << b << " is " << lcm << endl;
	return 0;
}