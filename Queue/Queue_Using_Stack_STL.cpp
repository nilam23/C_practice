#include <bits/stdc++.h>
using namespace std;

stack <int> s1, s2;

void enqueue(int item){
	while(!s1.empty()){
		s2.push(s1.top());
		s1.pop();
	}
	s1.push(item);
	while(!s2.empty()){
		s1.push(s2.top());
		s2.pop();
	}
	return;
}

int dequeue(){
	int item = s1.top();
	s1.pop();
	return item;
}

int main(){	
	enqueue(5);
	enqueue(3);
	enqueue(1);
	cout << dequeue() << endl;
	cout << dequeue() << endl;
	cout << dequeue() << endl;
	return 0;
}