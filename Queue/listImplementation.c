#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *link;
}Node;

Node *front = NULL;
Node *rear = NULL;

void insert(int item){
	Node *new=(Node *)malloc(sizeof(Node));
	if(new == NULL){
		printf("Queue overflow.\n");
		return;
	}
	new->data = item;
	new->link = NULL;
	if(front == NULL)
		front = new;
	else
		rear->link = new;
	rear = new;
}

int delete(){
	if(front == NULL){
		printf("Queue underflow.\n");
		return 0;
	}
	Node *t = front;
	int item = front->data;
	front = front->link;
	free(t);
	return item;
}

int peek(){
	if(front == NULL){
		printf("Queue underflow.\n");
		return 0;
	}
	return front->data;
}

void display(){
	if(front == NULL){
		printf("Queue underflow.\n");
		return;
	}
	Node *t = front;
	printf("The queue elements are: ");
	while(t){
		printf("%d\t", t->data);
		t = t->link;
	}
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
				printf("Inserted successfully.\n");
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