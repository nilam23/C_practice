#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *link;
}Node;

void Display(Node *last){
	if(last == NULL){
		printf("The list is empty.\n");
		return;
	}
	Node *t = last->link;
	printf("The list elements are: ");
	do{
		printf("%d ", t->data);
		t=t->link;
	}while(t != last->link);
}

int CountNodes(Node *last){
	if(last == NULL)
		return 0;
	Node *t = last->link;
	int count = 0;
	do{
		count++;
		t = t->link;
	}while(t != last->link);
	return count;
}

Node *InsertAtEmptyList(Node *last, int item){
	Node *new = (Node *)malloc(sizeof(Node));
	new->data = item;
	last = new;
	new->link = last;
	return last;
}

Node *InsertAtBeginning(Node *last, int item){
	if(last == NULL){
		last = InsertAtEmptyList(last, item);
		return last;
	}
	Node *new = (Node *)malloc(sizeof(Node));
	new->data = item;
	new->link = last ->link;
	last->link = new;
	return last;
}

Node *InsertAtEnd(Node *last, int item){
	if(last == NULL){
		last = InsertAtEmptyList(last, item);
		return last;
	}
	Node *new = (Node *)malloc(sizeof(Node));
	new->data = item;
	new->link = last->link;
	last->link = new;
	last = new;
	return last;
}

Node *InsertAtPosition(Node *last, int position, int item){
	int count = CountNodes(last);
	if(position <= 0){
		printf("Invalid position.\n");
		return last;
	}
	else if(position == 1){
		last = InsertAtBeginning(last, item);
		return last;
	}
	else if(position == count+1){
		last = InsertAtEnd(last, item);
		return last;
	}
	else if(position > count+1){
		printf("There are lesser nodes than %d in the list.\n", position-1);
		return last;
	}
	Node *t = last->link;
	for(int i=1; i<position-1; i++)
		t = t->link;
	Node *new = (Node *)malloc(sizeof(Node));
	new->data = item;
	new->link = t->link;
	t->link = new;
	printf("Inserted successfully.\n");
	return last;
}

Node *CreateList(Node *last){
	last = NULL;
	int N, item;
	printf("Enter no of nodes: ");
	scanf("%d", &N);
	if(N == 0){
		printf("List will contain no node.\n");
		return last;
	}
	printf("Enter the next element: ");
	scanf("%d", &item);
	last = InsertAtEmptyList(last, item);
	for(int i=2; i<=N; i++){
		printf("Enter the next element: ");
		scanf("%d", &item);
		last = InsertAtEnd(last, item);
	}
	return last;
}

Node *DeleteOnlyNode(Node *last){
	Node *t = last;
	last = NULL;
	free(t);
	printf("Deleted successfully.\n");
	return last;
}

Node *DeleteFromBeginning(Node *last){
	if(last == NULL){
		printf("The list is empty.\n");
		return last;
	}
	if(last->link == last)
		return DeleteOnlyNode(last);
	Node *t = last->link;
	last->link = t->link;
	free(t);
	printf("Deleted successfully.\n");
	return last;
}

Node *DeleteFromEnd(Node *last){
	if(last == NULL){
		printf("The list is empty.\n");
		return last;
	}
	if(last->link == last)
		return DeleteOnlyNode(last);
	Node *t = last->link;
	while(t->link != last)
		t=t->link;
	last = t;
	t = t->link;
	last->link = t->link;
	free(t);
	printf("Deleted successfully.\n");
	return last;
}

Node *DeleteFromPosition(Node *last, int position){
	if(last == NULL){
		printf("The list is empty.\n");
		return last;
	}
	int count = CountNodes(last);
	if(position <= 0){
		printf("Invalid position.\n");
		return last;
	}
	else if(position == 1){
		last = DeleteFromBeginning(last);
		return last;
	}
	else if(position == count){
		last = DeleteFromEnd(last);
		return last;
	}
	else if(position > count){
		printf("There are lesser nodes than %d in the list.\n", position);
		return last;
	}
	Node *p, *t = last->link;
	for(int i=1; i<position-1; i++)
		t = t->link;
	p = t->link;
	t->link = t->link->link;
	free(p);
	printf("Deleted successfully.\n");
	return last;
}

int main(){
	Node *last = NULL;
	int choice, item, position, count;
	while(1){
		printf("\n\n--PICK YOUR CHOICE--\n");
		printf("1. Create.\n");
		printf("2. Insert at the beginning.\n");
		printf("3. Insert at the end.\n");
		printf("4. Insert at position.\n");
		printf("5. Delete from the beginning.\n");
		printf("6. Delete from the end.\n");
		printf("7. Delete from position.\n");
		printf("8. Display.\n");
		printf("9. Count.\n");
		printf("10. Quit.\n");
		printf("Your choice? ");
		scanf("%d", &choice);
		printf("\n");
		switch(choice){
			case 1:
				last = CreateList(last);
				printf("List has been created successfully.\n");
				break;
			case 2:
				printf("Enter the element to be inserted: ");
				scanf("%d", &item);
				last = InsertAtBeginning(last, item);
				printf("Inserted successfully.\n");
				break;
			case 3:
				printf("Enter the element to be inserted: ");
				scanf("%d", &item);
				last = InsertAtEnd(last, item);
				printf("Inserted successfully.\n");
				break;
			case 4:
				printf("Enter the position: ");
				scanf("%d", &position);
				printf("Enter the element to be inserted: ");
				scanf("%d", &item);
				last = InsertAtPosition(last, position, item);
				break;
			case 5:
				last = DeleteFromBeginning(last);
				break;
			case 6:
				last = DeleteFromEnd(last);
				break;
			case 7:
				printf("Enter the position: ");
				scanf("%d", &position);
				last = DeleteFromPosition(last, position);
				break;
			case 8:
				Display(last);
				break;
			case 9:
				count = CountNodes(last);
				if(count == 0)
					printf("The list is empty.\n");
				else
					printf("No of nodes in the list: %d\n", count);
				break;
			case 10:
				printf("\n--EXITING--\n");
				exit(0);
			default:
				printf("Wrong choice. Re-enter again.\n");
				break;
		}
	}
	return 0;
}