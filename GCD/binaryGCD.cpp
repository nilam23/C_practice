#include<iostream>
#include<cmath>
using namespace std;

int binGCD(int a, int b){
	int commonMultipleOf2 = 1;
	while((a & 1) == 0 && (b & 1) == 0){
		commonMultipleOf2 = commonMultipleOf2 << 1;
		a = a >> 1;
		b = b >> 1;
	}
	while((a & 1) == 0)
		a = a >> 1;
	while((b & 1) == 0)
		b = b >> 1;
	while(b != 0){
		int temp = abs(a - b);
		a = b;
		b = temp;
		while((b & 1) == 0 && b > 0)
			b = b >> 1;
	}
	return a * commonMultipleOf2;
}

int main(){
	int a, b;
	cout << "Enter the first integer: ";
	cin >> a;
	cout << "Enter the second integer: ";
	cin >> b;
	cout << "GCD of " << a << " and " << b << ": " << binGCD(a, b) << endl;
	return 0;
}