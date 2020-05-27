#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int queue[MAX];
int front = 0;
int rear = 0;

void insert(int item){
	rear = (rear+1) % MAX;
	if(rear == front){
		printf("Queue is full.\n");
		if(rear == 0)
			rear = MAX-1;
		else
			rear--;
		return;
	}
	else{
		queue[rear] = item;
		return;
	}
}

int delete(){
	if(front == rear){
		printf("Queue is empty.\n");
		return 0;
	}
	else{
		front = (front+1) % MAX;
		return queue[front];
	}
}

int peek(){
	if(front == rear){
		printf("Queue is empty.\n");
		return 0;
	}
	else
		return queue[(front+1)%MAX];
}

void display(){
	if(front == rear){
		printf("Queue is empty.\n");
		return;
	}
	else{
		printf("The queue elements are: ");
		for(int i=(front+1)%MAX; i<=rear; i++)
			printf("%d ", queue[i]);
	}
}

int main(){
	int choice, item;
	while(1){
		printf("\n\n--PICK YOUR CHOICE--\n");
		printf("1. Insert.\n");
		printf("2. Delete.\n");
		printf("3. Display the front element.\n");
		printf("4. Display the elements in the queue.\n");
		printf("5. Quit.\n");
		printf("\nYour choice? ");
		scanf("%d", &choice);
		printf("\n");
		switch(choice){
			case 1:
				printf("Enter the element to be inserted: ");
				scanf("%d", &item);
				insert(item);
				break;
			case 2:
				item = delete();
				if(item == 0)
					break;
				printf("The deleted element is: %d\n", item);
				break;
			case 3:
				item = peek();
				if(item == 0)
					break;
				printf("The element at the front is: %d\n", item);
				break;
			case 4:
				display();
				break;
			case 5:
				printf("\n--EXITING--\n");
				exit(0);
			default:
				printf("Wrong choice. Re-enter again.\n");
				break;
		}
	}
	return 0;
}