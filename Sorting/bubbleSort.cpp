#include<iostream>
#define MAXSIZE 10000
using namespace std;

void bubbleSort(int arr[], int n){
	for(int i = 0; i < n-1; i++){
		int excanges = 0;
		for(int j = 0; j < n-1-i; j++){
			if(arr[j]>arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				excanges++;
			}
		}
		if(excanges == 0)
			break;
	}
}

int main(){
	int n, arr[MAXSIZE];
	cout << "Enter the size of the array: ";
	cin >> n;
	cout << "Enter the array elements: " << endl;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	cout << endl;
	bubbleSort(arr, n);
	cout << "After sorting:" << endl;
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;
}