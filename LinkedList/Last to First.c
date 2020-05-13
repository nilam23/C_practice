#include<stdio.h>
#include<stdlib.h>
#include "myListHeader.h"
struct node *LastToFirst(struct node *head){
	if(!head || !head->link)
		return head;
	struct node *p, *q;
	q=NULL;
	p=head;
	while(p->link){
		q=p;
		p=p->link;
	}
	p->link=head;
	head=q->link;
	q->link=NULL;
	return head;
}
int main(){
	struct node *head=NULL;
	head=CreateList(head);
	printf("\n--Before rearranging--\n");
	DisplayList(head);
	head=LastToFirst(head);
	printf("\n--After rearranging--\n");
	DisplayList(head);
	return 0;
}