#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
};
struct node *AddAtBeg(struct node *head, int item){
	struct node *new;
	new=(struct node *)malloc(sizeof(struct node));
	new->data=item;
	new->link=head;
	head=new;
	return head;
}
struct node *AddAtEnd(struct node *head, int item){
	struct node *t=head;
	while(t->link!=NULL)
		t=t->link;
	struct node *new;
	new=(struct node *)malloc(sizeof(struct node));
	new->data=item;
	new->link=NULL;
	t->link=new;
	return head;
}
struct node *CreateList(struct node *head){
	head=NULL;
	int n, item;
	printf("Enter no of nodes to be in the list: ");
	scanf("%d", &n);
	printf("Enter the next element: ");
	scanf("%d", &item);
	head=AddAtBeg(head, item);
	for(int i=2; i<=n; i++){
		printf("Enter the next element: ");
		scanf("%d", &item);
		head=AddAtEnd(head, item);
	}
	return head;
}
void display(struct node *head){
	struct node *t=head;
	printf("The data items of the list are:\n");
	while(t!=NULL){
		printf("%d ", t->data);
		t=t->link;
	}
	return ;
}
void getMaxMin(struct node *head){
	struct node *t=head;
	int max=t->data, min=t->data;
	while(t!=NULL){
		if(t->data>max)
			max=t->data;
		if(t->data<min)
			min=t->data;
		t=t->link;
	}
	printf("\nMin=%d, Max=%d\n", min, max);
	return ;
}
int main(){
	struct node *head=NULL;
	head=CreateList(head);
	display(head);
	getMaxMin(head);
	return 0;
}