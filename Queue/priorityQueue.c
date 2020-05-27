#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int priority;
	int data;
	struct node *link;
}Node;

Node *front = NULL;

void insert(int item, int priority){
	Node *t, *new = (Node *)malloc(sizeof(Node));
	if(new == NULL){
		printf("Heap space is unavailable.\n");
		return;
	}
	new->data = item;
	new->priority = priority;
	if(front == NULL || priority < front->priority){
		new->link = front;
		front = new;
	}
	else{
		t = front;
		while(t->link != NULL && t->link->priority <= priority)
			t = t->link;
		new->link = t->link;
		t->link = new;
	}
}

int delete(int *item, int *priority){
	if(front == NULL){
		printf("Queue is empty.\n");
		return 0;
	}
	Node *t = front;
	*item = front->data;
	*priority = front->priority;
	front = front->link;
	free(t);
	return 1;
}

void display(){
	if(front == NULL){
		printf("Queue is empty.\n");
		return;
	}
	printf("The Queue elements are:\n\n");
	printf("\tData\tPriority\n");
	Node *t = front;
	while(t){
		printf("\t%d\t%d\n", t->data, t->priority);
		t = t->link;
	}
	return;
}

int main(){
	int choice, priority, item, val;
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
				printf("Enter the priority: ");
				scanf("%d", &priority);
				insert(item, priority);
				break;
			case 2:
				val = delete(&item, &priority);
				if(val == 0)
					break;
				else
					printf("Deleted element is %d and it's priority %d\n", item, priority);
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