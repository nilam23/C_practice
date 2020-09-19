#include<iostream>
#define SIZE 100
using namespace std;

void selectionSort(int arr[], int size){
	for(int i = 0; i < size-1; i++){
		for(int j = i+1; j < size; j++){
			if(arr[j] < arr[i]){
				arr[i] = arr[i] + arr[j];
				arr[j] = arr[i] - arr[j];
				arr[i] = arr[i] - arr[j];
			}
		}
	}
}

int main(){
	int arr[SIZE], n;
	cout << "Enter no of elements of the array: ";
	cin >> n;
	cout << "Enter the array elements: " << endl;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	selectionSort(arr, n);
	cout << "--After sorting--" << endl;
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;
}