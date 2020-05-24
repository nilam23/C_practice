#include<stdio.h>
#include<stdlib.h>
#include "myHeader.h"
#define MAX 100

int stack[MAX];
int top = -1;

int isEmpty(){
	if(top == -1)
		return 1;
	else
		return 0;
}

int isFull(){
	if(top == MAX-1)
		return 1;
	else
		return 0;
}

void push(int item){
	if(isFull())
		printf("Overflow: Stack is full.\n");
	else
		stack[++top] = item;
	return ;
}

int pop(){
	if(isEmpty()){
		printf("Underflow: Stack is empty.\n");
		return -1;
	}
	int temp = stack[top--];
	return temp;
}

int peek(){
	if(isEmpty()){
		printf("Underflow: Stack is empty.\n");
		return -1;
	}
	else
		return stack[top];
}

void display(){
	if(isEmpty()){
		printf("Underflow: Stack is empty.\n");
		return ;
	}
	printStack(stack, top);
	return ;
}

int main(){
	int choice, item;
	while(1){
		printf("\n--PICK YOUR CHOICE--\n");
		printf("1. PUSH.\n");
		printf("2. POP.\n");
		printf("3. Display the Top element.\n");
		printf("4. Display all stack elements.\n");
		printf("5. Quit.\n");
		printf("\nYour choice? ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("Enter the item to be pushed: ");
				scanf("%d", &item);
				push(item);
				break;
			case 2:
				item = pop();
				if(item==-1)
					break;
				else
					printf("Popped item is: %d\n", item);
				break;
			case 3:
				if(peek()==-1)
					break;
				else
					printf("Item at the top is: %d\n", peek());
				break;
			case 4:
				display();
				break;
			case 5:
				printf("\n--EXITING--\n");
				exit(0);
			default:
				printf("Your choice is incorrect, re-eneter again.\n");
				break;
		}
	}
	return 0;
}