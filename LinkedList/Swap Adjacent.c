#include<stdio.h>
#include<stdlib.h>
#include "myListHeader.h"
struct node *SwapAdjacent(struct node *head){
	int temp;
	struct node *p, *q;
	if(!head || !head->link)
		return head;
	p=head;
	q=head->link;
	while(q){
		temp=p->data;
		p->data=q->data;
		q->data=temp;
		p=q->link;
		q=p?p->link:0;
		// q=p->link;		//fails for even no of nodes.
	}
	return head;
}
int main(){
	struct node *head=NULL;
	head=CreateList(head);
	printf("\n--Before rearranging--\n");
	DisplayList(head);
	head=SwapAdjacent(head);
	printf("\n--After rearranging--\n");
	DisplayList(head);
	return 0;
}