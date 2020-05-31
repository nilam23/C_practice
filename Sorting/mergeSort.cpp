#include<iostream>
#define MAX 100
using namespace std;

int aux[MAX] = {0};

void merge(int arr[], int low, int mid, int high){
	for(int k = low; k <= high; k++)
		aux[k] = arr[k];
	int i = low, j = mid+1;
	for(int k = low; k <= high; k++){
		if(i > mid)
			arr[k] = aux[j++];
		else if(j > high)
			arr[k] = aux[i++];
		else if(aux[j] < aux[i])
			arr[k] = aux[j++];
		else
			arr[k] = aux[i++];
	}
}

void mergeSort(int arr[], int low, int high){
	if(high <= low)
		return;
	int mid = low + (high - low)/2;
	mergeSort(arr, low, mid);
	mergeSort(arr, mid+1, high);
	merge(arr, low, mid, high);
}

int main(){
	int n, arr[MAX];
	cout << "Enter the size of the array: ";
	cin >> n;
	cout << "Enter the array: ";
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	mergeSort(arr, 0, n-1);
	cout << "After merge sorting: ";
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;
}