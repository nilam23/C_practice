#include<iostream>
#define MAX 10000
using namespace std;

void sort(int arr[], int n){
	int c0=0, c1=0, c2=0, i;
	for(i=0; i<n; i++){
		if(arr[i]==0)
			c0++;
		else if(arr[i]==1)
			c1++;
		else
			c2++;
	}
	i=0;
	while(c0--)
		arr[i++]=0;
	while(c1--)
		arr[i++]=1;
	while(c2--)
		arr[i++]=2;
}

int main(){
	int arr[MAX], n;
	cout << "Enter the size of the array: ";
	cin >> n;
	cout << "Enter the array elements one by one:" << endl;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, n);
	cout << "After sorting:" << endl;
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;
}