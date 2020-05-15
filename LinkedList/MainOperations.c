#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *link;
};

struct node *InsertAtBeginning(struct node *head, int item){
	struct node *new;
	new=(struct node*)malloc(sizeof(struct node));
	new->data=item;
	new->link=head;
	head=new;
	return head;
}

struct node *InsertAtEnd(struct node *head, int item){
	if(head==NULL){
		head=InsertAtBeginning(head, item);
		return head;
	}
	struct node *new, *t;
	new=(struct node *)malloc(sizeof(struct node));
	new->data=item;
	t=head;
	while(t->link!=NULL)
		t=t->link;
	t->link=new;
	new->link=NULL;
	return head;
}

struct node *CreateList(struct node *head){
	int n, data;
	printf("Enter the no of nodes: ");
	scanf("%d", &n);
	head=NULL;
	if(n==0)
		return head;
	printf("Enter the element to be inserted: ");
	scanf("%d", &data);
	head=InsertAtBeginning(head, data);
	for(int i=1; i<n; i++){
		printf("Enter the element to be inserted: ");
		scanf("%d", &data);
		head=InsertAtEnd(head, data);
	}
	return head;
}

void DisplayList(struct node *head){
	if(head==NULL){
		printf("List is empty.\n");
		return ;
	}
	struct node *t=head;
	printf("Data items of the list are:\n");
	while(t!=NULL){
		printf("%d\t", t->data);
		t=t->link;
	}
	printf("\n");
	return ;
}

int CountNodes(struct node *head){
	struct node *t=head;
	int count=0;
	while(t!=NULL){
		count++;
		t=t->link;
	}
	return count;
}

void SearchItem(struct node *head, int item){
	struct node *t=head;
	int pos=1;
	while(t!=NULL){
		if(t->data==item){
			printf("FOUND. Position=%d\n", pos);
			return;
		}
		t=t->link;
		pos++;
	}
	printf("NOT FOUND.\n");
	return;
}

struct node *InsertAfterNode(struct node *head, int item, int data){
	if(head==NULL){
		printf("List is empty.\n");
		return head;
	}
	struct node *t=head;
	
	while(t!=NULL){
		if(t->data==data){
			struct node *new;
			new=(struct node *)malloc(sizeof(struct node));
			new->data=item;
			new->link=t->link;
			t->link=new;
			return head;
		}
		t=t->link;
	}
	printf("%d is not data item of any of the nodes.\n", data);
	return head;
}

struct node *InsertBeforeNode(struct node *head, int item, int data){
	if(head==NULL){
		printf("List is empty.\n");
		return head;
	}
	struct node *t;
	if(head->data==data){
		head=InsertAtBeginning(head, item);
		return head;
	}
	t=head;
	while(t->link!=NULL){
		if(t->link->data==data){
			struct node *new;
			new=(struct node *)malloc(sizeof(struct node));
			new->data=item;
			new->link=t->link;
			t->link=new;
			return head;
		}
		t=t->link;
	}
	printf("%d is not data item of any of the nodes.\n", data);
	return head;
}

struct node *InsertAtPosition(struct node *head, int item, int pos){
	if(pos==0){
		printf("0 is not a valid position.\n");
		return head;
	}
	if(pos==1){
		head=InsertAtBeginning(head, item);
		return head;
	}
	int count=CountNodes(head);
	if(count==pos-1){
		head=InsertAtEnd(head, item);
		return head;
	}
	struct node *t=head;
	for(int i=1; i<pos-1; i++){
		if(t==NULL)
			continue;
		t=t->link;
	}
	if(t==NULL){
		printf("There are fewer nodes than %d.\n", pos-1);
		return head;
	}
	head=InsertAfterNode(head, item, t->data);
	return head;
}

struct node *DeleteFromBeginning(struct node *head){
	if(head==NULL){
		printf("List is empty.\n");
		return head;
	}
	struct node *t=head;
	head=t->link;
	free(t);
	return head;
}

struct node *DeleteFromEnd(struct node *head){
	if(head==NULL){
		printf("List is empty.\n");
		return head;
	}
	struct node *t=head;
	if(head->link==NULL){
		head=NULL;
		free(t);
		return head;
	}
	while(t->link->link!=NULL)
		t=t->link;
	free(t->link);
	t->link=NULL;
	return head;
}

struct node *DeleteAtPosition(struct node *head, int pos){
	if(head==NULL){
		printf("List is empty.\n");
		return head;
	}
	if(pos==0){
		printf("0 is not a valid position.\n");
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
	struct node *t=head;
	for(int i=1; i<pos; i++){
		if(t==NULL)
			continue;
		t=t->link;
	}
	if(t==NULL){
		printf("There are fewer nodes than %d\n", pos);
		return head;
	}
	struct node *t1;
	t1=t->link;
	t->link=t->link->link;
	free(t1);
	return head;
}

int main(){
	struct node *head=NULL;
	while(1){
		printf("\n--Pick your choice--\n");
		printf("1. Create a new list.\n");
		printf("2. Display the list.\n");
		printf("3. Count the no of nodes.\n");
		printf("4. Search an item.\n");
		printf("5. Add at the beginning.\n");
		printf("6. Add at the end.\n");
		printf("7. Add after a node.\n");
		printf("8. Add before a node.\n");
		printf("9. Add at a given position.\n");
		printf("10. Delete from the beginning.\n");
		printf("11. Delete from the end.\n");
		printf("12. Delete at position.\n");
		printf("13. Quit.\n");
		int choice, count, item, data, pos;
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
				printf("Total no of nodes in the list: %d\n", count);
				break;
			case 4:
				printf("Enter the item to be searched in the list: ");
				scanf("%d", &item);
				SearchItem(head, item);
				break;
			case 5:
				printf("Enter the element to be inserted: ");
				scanf("%d", &data);
				head=InsertAtBeginning(head, data);
				break;
			case 6:
				printf("Enter the element to be inserted: ");
				scanf("%d", &data);
				head=InsertAtEnd(head, data);
				break;
			case 7:
				printf("Enter the element to be inserted: ");
				scanf("%d", &data);
				printf("Enter the data of the target node: ");
				scanf("%d", &item);
				head=InsertAfterNode(head, data, item);
				break;
			case 8:
				printf("Enter the element to be inserted: ");
				scanf("%d", &data);
				printf("Enter the data of the target node: ");
				scanf("%d", &item);
				head=InsertBeforeNode(head, data, item);
				break;
			case 9:
				printf("Enter the element to be inserted: ");
				scanf("%d", &data);
				printf("Enter the position of insertion: ");
				scanf("%d", &pos);
				head=InsertAtPosition(head, data, pos);
				break;
			case 10:
				head=DeleteFromBeginning(head);
				break;
			case 11:
				head=DeleteFromEnd(head);
				break;
			case 12:
				printf("Enter the position of the node to be deleted: ");
				scanf("%d", &pos);
				head=DeleteAtPosition(head, pos);
				break;
			case 13:
				printf("--Exiting--\n");
				exit(0);
			default:
				printf("Enter a valid choice.\n");
				break;
		}
	}
	return 0;
}
