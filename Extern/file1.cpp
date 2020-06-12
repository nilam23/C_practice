#include<iostream>
using namespace std;

int count;
extern void show();

int main(){
	count = 5;
	show();
	return 0;
}