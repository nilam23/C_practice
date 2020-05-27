#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int priority;
	int data;
	struct node *link;
}Node;

Node *front = NULL;

void insert(int item){
	Node *t, *new = (Node *)malloc(sizeof(Node));
	if(new == NULL){
		printf("Heap space is unavailable.\n");
		return;
	}
	new->data = item;
	if(front == NULL || item < front->data){
		new->link = front;
		front = new;
	}
	else{
		t = front;
		while(t->link != NULL && t->link->data < item)
			t = t->link;
		new->link = t->link;
		t->link = new;
	}
}

int delete(){
	if(front == NULL){
		printf("Queue is empty.\n");
		return 0;
	}
	Node *t = front;
	int item = front->data;
	front = front->link;
	free(t);
	return item;
}

void display(){
	if(front == NULL){
		printf("Queue is empty.\n");
		return;
	}
	printf("The Queue elements are: ");
	Node *t = front;
	while(t){
		printf("%d ", t->data);
		t = t->link;
	}
	return;
}

int main(){
	int choice, item;
	while(1){
		printf("\n\n--PICK YOUR CHOICE--\n");
		printf("1. Insert.\n");
		printf("2. Delete.\n");
		printf("3. Display.\n");
		printf("4. Quit.\n");
		printf("Your choice? ");
		scanf("%d", &choice);
		printf("\n");
		switch(choice){
			case 1:
				printf("Enter the element: ");
				scanf("%d", &item);
				insert(item);
				break;
			case 2:
				item = delete();
				if(item == 0)
					break;
				else
					printf("Deleted element is %d\n", item);
				break;
			case 3:
				display();
				break;
			case 4:
				printf("\n--EXITING--\n");
				exit(0);
			default:
				printf("Wrong choice. Re-enter again.\n");
				break;
		}
	}
	return 0;
}