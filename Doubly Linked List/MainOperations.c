#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *prev;
	struct node *next;
}Node;

void DisplayList(Node *t){
	if(t==NULL){
		printf("List is empty.\n");
		return;
	}
	printf("The list elements are: \n");
	while(t){
		printf("%d ", t->data);
		t=t->next;
	}
	printf("\n");
	return;
}

int CountNodes(Node *t){
	int count=0;
	while(t){
		count++;
		t=t->next;
	}
	return count;
}


Node *AddAtBeginning(Node *head, int item){
	Node *new=(Node *)malloc(sizeof(Node));
	new->data=item;
	if(head==NULL){
		new->prev=NULL;
		new->next=NULL;
		head=new;
		return head;
	}
	new->prev=NULL;
	new->next=head;
	head->prev=new;
	head=new;
	return head;
}

Node *AddAtEnd(Node *head, int item){
	if(head==NULL){
		head=AddAtBeginning(head, item);
		return head;
	}
	Node *t=head, *new;
	new=(Node *)malloc(sizeof(Node));
	while(t->next)
		t=t->next;
	new->data=item;
	new->next=NULL;
	new->prev=t;
	t->next=new;
	return head;
}

Node *CreateList(Node *head){
	int n, item;
	printf("Enter total no of nodes in the list: ");
	scanf("%d", &n);
	if(n==0)
		return head;
	printf("Enter the next element: ");
	scanf("%d", &item);
	head=AddAtBeginning(head, item);
	for(int i=2; i<=n; i++){
		printf("Enter the next element: ");
		scanf("%d", &item);
		head=AddAtEnd(head, item);
	}
	return head;
}

Node *AddAtPosition(Node *head, int item, int pos){
	if(pos==0){
		printf("0 is not a valid position.\n");
		return head;
	}
	if(pos==1){
		head=AddAtBeginning(head, item);
		return head;
	}
	int count=CountNodes(head);
	if(count==pos-1){
		head=AddAtEnd(head, item);
		return head;
	}
	Node *t=head, *new;
	for(int i=1; i<pos-1; i++){
		if(t==NULL)
			continue;
		t=t->next;
	}
	if(t==NULL){
		printf("There are fewer nodes than %d.\n", pos-1);
		return head;
	}
	new=(Node *)malloc(sizeof(Node));
	new->data=item;
	new->next=t->next;
	new->prev=t;
	t->next->prev=new;
	t->next=new;
	return head;
}

Node *DeleteFromBeginning(Node *head){
	if(!head){
		printf("List is empty.\n");
		return head;
	}
	Node *t=head;
	if(!head->next){
		head=NULL;
		free(t);
		return head;
	}
	head=head->next;
	head->prev=NULL;
	free(t);
	return head;
}

Node *DeleteFromEnd(Node *head){
	if(!head){
		printf("List is empty.\n");
		return 0;
	}
	Node *t=head;
	if(!head->next){
		head=NULL;
		free(t);
		return head;
	}
	while(t->next)
		t=t->next;
	t->prev->next=NULL;
	free(t);
	return head;
}

Node *DeleteAtPosition(Node *head, int pos){
	if(pos==0){
		printf("0 isn't a valid position.\n");
		return head;
	}
	if(pos==1){
		head=DeleteFromBeginning(head);
		return head;
	}
	int count=CountNodes(head);
	if(pos==count){
		head=DeleteFromEnd(head);
		return head;
	}
	Node *t=head;
	for(int i=1; i<pos; i++){
		if(t==NULL)
			continue;
		t=t->next;
	}
	if(t==NULL){
		printf("There are fewer than %d nodes in the list.\n", pos);
		return head;
	}
	t->prev->next=t->next;
	t->next->prev=t->prev;
	free(t);
	return head;
}

int main(){
	Node *head=NULL;
	while(1){
		printf("\n--PICK YOUR CHOICE--\n");
		printf("1. Create a new DLL.\n");
		printf("2. Display the DLL.\n");
		printf("3. Count the no of nodes in the DLL.\n");
		printf("4. Insert element at the beginning.\n");
		printf("5. Insert element at the end.\n");
		printf("6. Insert at a given position.\n");
		printf("7. Delete from the beginning.\n");
		printf("8. Delete from the end.\n");
		printf("9. Delete from a given position.\n");
		printf("10. Quit.\n");
		int choice, count, item, pos;
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				head=CreateList(head);
				break;
			case 2:
				DisplayList(head);
				break;
			case 3:
				count=CountNodes(head);
				printf("There are %d nodes in the DLL.\n", count);
				break;
			case 4:
				printf("Enter the element to be added at the start: ");
				scanf("%d", &item);
				head=AddAtBeginning(head, item);
				break;
			case 5:
				printf("Enter the element to be added at the end: ");
				scanf("%d", &item);
				head=AddAtEnd(head, item);
				break;
			case 6:
				printf("Enter the element to be added: ");
				scanf("%d", &item);
				printf("Enter the new position: ");
				scanf("%d", &pos);
				head=AddAtPosition(head, item, pos);
				break;
			case 7:
				head=DeleteFromBeginning(head);
				break;
			case 8:
				head=DeleteFromEnd(head);
				break;
			case 9:
				printf("Enter position where deletion needs to be done: ");
				scanf("%d", &pos);
				head=DeleteAtPosition(head, pos);
				break;
			case 10:
				printf("\n--EXITING--\n");
				exit(0);
			default:
				printf("Enter a valid choice.\n");
				break;
		}
	}
	return 0;
}
