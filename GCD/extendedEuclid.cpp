#include<iostream>
using namespace std;
int gcd(int a, int b, int &x, int &y){
	if(b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	int x1, y1;
	int g = gcd(b, a%b, x1, y1);
	x = y1;
	y = x1 - y1 * (a / b);
	return g;
}
int main(){
	int a, b, x, y;
	cout << "Enter the first integer: ";
	cin >> a;
	cout << "Enter the second integer: ";
	cin >> b;
	cout << "GCD is: " << gcd(a, b, x, y) << endl;
	cout << "Co-efficients (x, y) are: (" << x << ", " << y << ")" << endl;
	return 0;
}