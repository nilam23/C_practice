#include<stdlib.h>
#include<stdio.h>

typedef struct node{
	int data;
	struct node *link;
}Node;

Node *rear = NULL;

void insert(int item){
	Node *new = (Node *)malloc(sizeof(Node));
	if(new ==  NULL){
		printf("Queue is full.\n");
		return;
	}
	new->data = item;
	if(rear == NULL){
		rear = new;
		new->link = rear;
	}
	else{
		new->link = rear->link;
		rear->link = new;
		rear = new;
	}
}

int delete(){
	if(rear == NULL){
		printf("Queue is empty.\n");
		return 0;
	}
	Node *t = rear->link;
	if(rear->link == rear)
		rear = NULL;
	else
		rear->link = t->link;
	int item = t->data;
	free(t);
	return item;
}

int peek(){
	if(rear == NULL){
		printf("Queue is empty.\n");
		return 0;
	}
	return rear->link->data;
}

void display(){
	if(rear == NULL){
		printf("Queue is empty.\n");
		return;
	}
	Node *t = rear;
	printf("The queue elements are: ");
	do{
		printf("%d ", t->link->data);
		t = t->link;
	}while(t!=rear);
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