#include<iostream>
#define l long int
using namespace std;
l getCount(l n){
	int count = 0;
	cout << "Possible combinations are:" << endl;
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++){
			for(int k = 0; k <= n; k++){
				if(i+j+k == n){
					cout << i << "+" << j << "+" << k << "=" << n << endl;
					count++;
				}
			}
		}
	}
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