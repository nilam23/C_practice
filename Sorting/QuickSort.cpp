#include<iostream>
#define MAX_SIZE 10000
using namespace std;

void Swap(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}

int Partition(int *arr, int l, int r){
	int pivot = arr[r];
	int i, j;
	i = l - 1;
	for(int j = l; j < r; j++){
		if(arr[j] <= pivot){
			i++;
			Swap(&arr[i], &arr[j]);
		}
	}
	Swap(&arr[i+1], &arr[r]);
	return i+1;
}

void Quicksort(int *arr, int l, int r){
	if(l < r){
		int p = Partition(arr, l, r);
		Quicksort(arr, l, p-1);
		Quicksort(arr, p+1, r);
	}
	return;
}

int main(){
	int n, arr[MAX_SIZE];
	cout << "Enter the size of the array: ";
	cin >> n;
	cout << "Enter the array element one by one:" << endl;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	cout << "Before sorting:" << endl;
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
	Quicksort(arr, 0, n-1);
	cout << "After sorting:" << endl;
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;
}