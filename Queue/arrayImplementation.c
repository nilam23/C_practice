#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

void insert(int item){
	if(rear == MAX-1){
		printf("Queue is full.\n");
		return;
	}
	if(front == -1)
		front = 0;
	queue[++rear] = item;
	return;
}

int delete(){
	if(front == -1 || front == rear+1){
		printf("Queue is empty.\n");
		return 0;
	}
	int temp = queue[front++];
	return temp;
}

int peek(){
	if(front == -1 || front == rear+1){
		printf("Queue is empty.\n");
		return 0;
	}
	return queue[front];
}

void display(){
	if(front == -1 || front == rear+1){
		printf("Queue is empty.\n");
		return;
	}
	printf("The queue elements are: ");
	for(int i=front; i<=rear; i++)
		printf("%d\t", queue[i]);
	printf("\n");
}

int main(){
	int choice, item;
	while(1){
		printf("\n--PICK YOUR CHOICE--\n");
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