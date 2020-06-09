#include<iostream>
using namespace std;
int getGCD(int a, int b){
	return (b ? getGCD(b, a%b) : a);
}
int getMMI(int a, int p){
	//a = a % p;
	for(int x = 1; x < p; x++){
		if((a * x) % p == 1)
			return x;
	}
}
int main(){
	int a, p;
	cout << "Enter a: ";
	cin >> a;
	cout << "Enter p: ";
	cin >> p;
	int gcd = getGCD(a, p);
	if(gcd == 1)
		cout << "Result = " << getMMI(a, p) << endl;
	else
		cout << a << " and " << p << " are not co-primes." << endl;
	return 0;
}