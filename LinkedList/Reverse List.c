#include<stdio.h>
#include<stdlib.h>
#include "myListHeader.h"
struct node *ReverseList(struct node *current){
	struct node *previous, *next;
	previous=NULL;
	next=NULL;
	while(current){
		next=current->link;
		current->link=previous;
		previous=current;
		current=next;
	}
	return previous;
}
int main(){
	struct node *head=NULL;
	head=CreateList(head);
	printf("\n--Before--\n");
	DisplayList(head);
	head=ReverseList(head);
	printf("\n--After--\n");
	DisplayList(head);
	return 0;
}