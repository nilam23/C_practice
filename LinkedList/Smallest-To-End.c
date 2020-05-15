#include<stdio.h>
#include<stdlib.h>
#include"myListHeader.h"
struct node *Process(struct node *head, int item){
	struct node *t=head, *p;
	if(head->link==NULL)
		return head;
	if(head->data==item){
		p=t;
		t=t->link;
		head=t;
		p->link=NULL;
		while(t->link != NULL)
			t=t->link;
		t->link=p;
		return head;
	}
	while(t->link->data!=item)
		t=t->link;
	p=t->link;
	t->link=p->link;
	p->link=NULL;
	while(t->link != NULL)
		t=t->link;
	t->link=p;
	return head;
}
int GetMin(struct  node *t){
	int min=t->data;
	while(t){
		if(t->data<min)
			min=t->data;
		t=t->link;
	}
	return min;
}
int main(){
	struct node *head=NULL;
	head=CreateList(head);
	printf("\n--BEFORE--\n");
	DisplayList(head);
	int min=GetMin(head);
	printf("\nThe minimum of the list is= %d\n", min);
	head=Process(head, min);
	printf("\n--AFTER--\n");
	DisplayList(head);
	return 0;
}