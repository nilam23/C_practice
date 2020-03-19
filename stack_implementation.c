#include<stdio.h>
#include<stdlib.h>
#define max 10

int stack[max];
int top=-1;

void push(int item){
	stack[++top]=item;
	return;
}

int pop(){
	int temp;
	temp=stack[top--];
	return temp;
}

int isFull(){
	if(top==max-1)
		return 1;
	else
		return 0;
}

int isEmpty(){
	if(top==-1)
		return  1;
	else
		return 0;
}

void printStack(){
	printf("Current stack elements are:\n");
	for (int i=0; i<=top; i++)
	{
		printf("%d\t", stack[i]);
	}
	printf("\n");
	return;
}

int main()
{
	// int choice, item;
	// printf("Do you want to push (1) an element or pop off (2) an element?\n");
	// scanf("%d", &choice);
	// switch(choice){
	// 	case 1:
	// 		if(isFull()){
	// 			printf("Stack is full.\n");
	// 			break;
	// 		}
	// 		else{
	// 			printf("Enter an element to be pushed into the stack: ");
	// 			scanf("%d", &item);
	// 			push(item);
	// 			break;
	// 		}
	// 	case 2:
	// 		if(isEmpty()){
	// 			printf("Stack is empty.\n");
	// 			break;
	// 		}
	// 		else{
	// 			printf("The element popped off from the top of the stack is: %d\n", pop());
	// 			break;
	// 		}
	// }

	int choice, item;
	while(1){
		printf("Do you want to push (1) an element or pop off (2) an element?\n");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				if(isFull()){
					printf("Overflow: Stack is full.\n");
					printStack();
					break;
				}
				else{
					printf("Enter an element to be pushed into the stack: ");
					scanf("%d", &item);
					push(item);
					printStack();
					break;
				}
			case 2:
				if(isEmpty()){
					printf("Underflow:Stack is empty.\n");
					printStack();
					break;
				}
				else{
					printf("The element popped off from the top of the stack: %d\n", pop());
					printStack();
					break;
				}
			default:
				printf("Enter either 1 (to push) or 2 (to pop).\n");
				break;
		}
	}
	return 0;
}