#include<iostream>
#define MAX 10000
using namespace std;

void reverse(int arr[], int l, int r){
	while(l<r){
		arr[l] = arr[l] + arr[r];
		arr[r] = arr[l] - arr[r];
		arr[l] = arr[l] - arr[r];
		l++;
		r--;
	}
}

int main(){
	int arr[MAX], n;
	cout << "Enter the size of the array: ";
	cin >> n;
	cout << "Enter the array elements one by one:" << endl;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	reverse(arr, 0, n-1);
	cout << "After reverse:" << endl;
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;
}