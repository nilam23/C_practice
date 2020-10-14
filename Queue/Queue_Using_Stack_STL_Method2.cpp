#include <bits/stdc++.h>
using namespace std;

stack <int> s1, s2;

inline void enqueue(int item){
	s1.push(item);
	return;
}

int dequeue(){
	if(s1.empty()){
		cout << "Queue is empty." << endl;
		return 0;
	}
	while(!s1.empty()){
		s2.push(s1.top());
		s1.pop();
	}
	int item = s2.top();
	s2.pop();
	while(!s2.empty()){
		s1.push(s2.top());
		s2.pop();
	}
	return item;
}

int main(){
	enqueue(5);
	enqueue(4);
	enqueue(8);
	cout << dequeue() << endl;
	cout << dequeue() << endl;
	cout << dequeue() << endl;
	cout << dequeue() << endl;
	return 0;
}