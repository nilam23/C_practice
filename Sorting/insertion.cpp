#include<iostream>
#define MAX 100
#define isLess(a, b) (a < b ? 1 : 0)
using namespace std;
void insertionSort(int *arr, int size){
	for(int i = 0; i < size; i++){
		for(int j = i; j > 0; j-- ){
			if(isLess(arr[j], arr[j-1])){
				arr[j] = arr[j] + arr[j-1];
				arr[j-1] = arr[j] - arr[j-1];
				arr[j] = arr[j] - arr[j-1];
			}
			else
				break;
		}
	}
}
int main(){
	int n, arr[MAX];
	cout << "Enter the size of the array: ";
	cin >> n;
	cout << "Enter the array as a single line: ";
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	insertionSort(arr, n);
	cout << "After insertion sort: ";
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	endl(cout);
	return 0;
}