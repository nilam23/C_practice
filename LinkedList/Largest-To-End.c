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
int GetMax(struct  node *t){
	int max=t->data;
	while(t){
		if(t->data>max)
			max=t->data;
		t=t->link;
	}
	return max;
}
int main(){
	struct node *head=NULL;
	head=CreateList(head);
	printf("\n--BEFORE--\n");
	DisplayList(head);
	int max=GetMax(head);
	printf("\nThe maximum of the list is= %d\n", max);
	head=Process(head, max);
	printf("\n--AFTER--\n");
	DisplayList(head);
	return 0;
}