#include<iostream>
using namespace std;
int extEuclid(int a, int b, int &x, int &y){
	if(b == 0){
		x = a;
		y = 0;
		return a;
	}
	int x1, y1;
	int gcd = extEuclid(b, a%b, x1, y1);
	x = y1;
	y = x1 - y1 * (a/b);
	return gcd;
}
void findMMI(int a, int p){
	int x, y, gcd;
	gcd = extEuclid(a, p, x, y);
	if(gcd != 1){
		cout << a << " and " << p << " are not co-primes." << endl;
		return;
	}
	x = (x % p + p) % p;
	cout << "Modular inverse of " << a << " = " << x << endl;
	return;
}
int main(){
	int a, p;
	cout << "Enter a: ";
	cin >> a;
	cout << "Enter p: ";
	cin >> p;
	findMMI(a, p);
	return 0;
}