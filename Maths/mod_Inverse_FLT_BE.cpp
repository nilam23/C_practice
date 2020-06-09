#include<iostream>
#include<cmath>
using namespace std;
int checkPrime(int m){
	if(m <= 1)
		return 0;
	for(int i = 2; i <= sqrt(m); i++){
		if(m % i == 0)
			return 0;
	}
	return 1;
}
int gcd(int a, int b){
	return b ? gcd(b, a%b) : a;
}
int binExpo(int a, int n, int m){
	if(n == 0)
		return 1;
	else if(n == 1)
		return a % m;
	int res = binExpo(a, n/2, m);
	if(n % 2 == 0)
		return (res * res) % m;
	else
		return (res * res * a) % m;
}
void modInverse(int a, int m){
	if(gcd(a, m) != 1){
		cout << "Modular inverse doesn't exist." << endl;
		return;
	}
	cout << "Modular inverse of " << a << " under mod " << m << " is " << binExpo(a, m-2, m);
	return;
}
int main(){
	int a, m;
	cout << "Enter any integer: ";
	cin >> a;
	cout << "Enter a prime no: ";
	cin >> m;
	if(!checkPrime(m))
		cout << m << " is not a prime no." << endl;
	modInverse(a, m);
	return 0;
}