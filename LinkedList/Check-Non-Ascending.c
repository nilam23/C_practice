#include<stdio.h>
#include<stdlib.h>
#include "myListHeader.h"
int CheckList(struct node *t){
	return ( (!t) || (!t->link) || ((t->data >= t->link->data) && CheckList(t->link)) );
}
int main(){
	struct node *head=NULL;
	head=CreateList(head);
	DisplayList(head);
	if(CheckList(head))
		printf("YES.\n");
	else
		printf("NO.\n");
	return 0;
}