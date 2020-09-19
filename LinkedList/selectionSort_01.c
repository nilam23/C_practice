#include<stdio.h>
#include<stdlib.h>
#include "myListHeader.h"

struct node * selectionSort(struct node *head){
	struct node *p, *q;
	for(p=head; p->link; p=p->link){
		for(q=p->link; q; q=q->link){
			if(q->data < p->data){
				int temp = q->data;
				q->data = p->data;
				p->data = temp;
			}
		}
	}
	return head;
}

int main(){
	struct node *head = NULL;
	head = CreateList(head);
	DisplayList(head);
	head = selectionSort(head);
	DisplayList(head);
	return 0;
}