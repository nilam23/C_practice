#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *link;
}Node;

Node *top = NULL;

void push(int item){
	Node *new = (Node *)malloc(sizeof(Node));
	if(new == NULL){
		printf("Overflow: Stack is full.\n");
		return;
	}
	new->data = item;
	new->link = top;
	top = new;
	return;
}

int pop(){
	if(top == NULL){
		printf("Underflow: Stack is empty.\n");
		return -1;
	}
	int item = top->data;
	Node *temp = top;
	top = temp->link;
	free(temp);
	return item;
}

int peek(){
	if(top == NULL){
		printf("Underflow: Stack is empty.\n");
		return -1;
	}
	return top->data;
}

void display(){
	Node *temp = top;
	printf("Stack elements are: ");
	while(temp){
		printf("%d ", temp->data);
		temp = temp->link;
	}
	return;
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