#include<iostream>
#include<cstring>
#define MAX 100
using namespace std;

int aux[MAX];

void merge(int arr1[], int n1, int arr2[], int n2){
	memset(aux, 0, sizeof(aux));
	int i = 0, j = 0, k;
	for(k = 0; k < n1+n2; k++){
		if(i == n1)
			aux[k] = arr2[j++];
		else if(j == n2)
			aux[k] = arr1[i++];
		else if(arr2[j] < arr1[i])
			aux[k] = arr2[j++];
		else
			aux[k] = arr1[i++];
	}
}

int main(){
	int n1, n2, arr1[MAX], arr2[MAX];
	cout << "Enter the size of the first array: ";
	cin >> n1;
	cout << "Enter the first sorted array: ";
	for(int i = 0; i < n1; i++)
		cin >> arr1[i];
	cout << "Enter the size of the second array: ";
	cin >> n2;
	cout << "Enter the second sorted array: ";
	for(int i = 0; i < n2; i++)
		cin >> arr2[i];
	cout << "After merging the arrays: ";
	merge(arr1, n1, arr2, n2);
	for(int i = 0; i < n1+n2; i++)
		cout << aux[i] << " ";
	return 0;
}