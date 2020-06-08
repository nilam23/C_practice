#include<iostream>
#define ll long long int
using namespace std;
ll binExpo(int a, int n){
	if(n == 0)
		return 1;
	ll result = 1;
	while(n > 0){
		if(n & 1)
			result *= a;
		a *= a;
		n >>= 1;
	}
	return result;
}
int main(){
	int a, n;
	cout << "Enter the integer: ";
	cin >> a;
	cout << "Enter the power: ";
	cin >> n;
	cout << "Result = " << binExpo(a, n) << endl;
	return 0;
}