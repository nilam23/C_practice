#include<iostream>
#define ll long long int
using namespace std;
ll power(int a, int n){
	if(n == 0)
		return 1;
	ll result = power(a, n/2) * power(a, n/2);
	if(n & 1)
		return result * a;
	else
		return result;
}
int main(){
	int a, n;
	cout << "Enter the integer: ";
	cin >> a;
	cout << "Enter the power: ";
	cin >> n;
	cout << "Result = " << power(a, n) << endl;
	return 0;
}