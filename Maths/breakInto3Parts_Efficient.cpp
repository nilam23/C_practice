#include<iostream>
#define l long int
using namespace std;
l getCount(l n){
	int count = (n + 1) * (n + 2) / 2;
	return count;
}
int main(){
	l n;
	cout << "The integer: ";
	cin >> n;
	l count = getCount(n);
	cout << "Total combinations: " << count << endl;
	return 0;
}