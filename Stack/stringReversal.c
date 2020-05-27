#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50
char stack[MAX];
int top = -1;
void push(char ch){
	if(top == MAX-1){
		printf("Stack is full.");
		return;
	}
	stack[++top] = ch;
}
char pop(){
	if(top==-1){
		printf("Stack is empty.\n");
		exit(0);
	}
	return stack[top--];
}
int main(){
	char str[20];
	printf("Enter the string: ");
	gets(str);
	for(int i=0; i<strlen(str); i++)
		push(str[i]);
	for(int i=0; i<strlen(str); i++)
		str[i] = pop();
	printf("After reversing: ");
	puts(str);
	return 0;
}