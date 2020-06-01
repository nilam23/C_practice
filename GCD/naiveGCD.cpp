#include<iostream>
#define MAX 100
using namespace std;
int gcd(int a, int b){
	int fa[MAX], fb[MAX], fc[MAX];
	int i = 0, j = 0, k = 0;
	for(int term = 1; term <= a; term++){
		if(a % term == 0)
			fa[i++] = term;
	}
	for(int term = 1; term <= b; term++){
		if(b % term == 0)
			fb[j++] = term;
	}
	for(int term_A = 0; term_A < i; term_A++){
		for(int term_B = 0; term_B < j; term_B++){
			if(fa[term_A] == fb[term_B]){
				fc[k++] = fa[term_A];
				break;
			}
		}
	}
	return fc[k-1];
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