#include<iostream>
#define MAXSIZE 10000
using namespace std;

class Stack{
	int top;
	int s[MAXSIZE];
public:
	Stack(void);
	void push(int);
	int pop();
	int empty();
	void display();
};

Stack::Stack(void){
	top = -1;
}

void Stack::push(int item){
	s[++top] = item;
	return;
}

int Stack::pop(){
	if(empty()){
		cout << "Stack is empty." << endl;
		return 0;
	}
	int item = s[top--];
	return item;
}

int Stack::empty(){
	if(top==-1)
		return 1;
	return 0;
}

void Stack::display(){
	if(empty()){
		cout << "Initially, queue is empty." << endl;
		return;
	}
	cout << "Queue elements are: " << endl;
	for(int i = top; i >= 0; i--)
		cout << s[i] << " ";
	cout << endl;
}

Stack s1, s2;

void enqueue(int item){
	while(!s1.empty())
		s2.push(s1.pop());
	s1.push(item);
	while(!s2.empty())
		s1.push(s2.pop());
	return;
}

int dequeue(){
	if(s1.empty()){
		printf("Queue is empty.\n");
		return 0;
	}
	int item = s1.pop();
	return item;
}

int main(){
	s1.display();
	enqueue(5);
	enqueue(3);
	enqueue(1);
	enqueue(8);
	cout << "--After inserting few elements into the queue--" << endl;
	s1.display();
	cout << "--After performing some deletion operations--" << endl;
	cout << dequeue() << endl;
	cout << dequeue() << endl;
	cout << dequeue() << endl;
	cout << dequeue() << endl;
	return 0;
}