#include<stdio.h>
#include<stdlib.h>
#include "myListHeader.h"
void traverse(struct node *t){
	if(t){
		traverse(t->link); // w/o recursion we'll lose track of prev nodes
		printf("%d ", t->data);
	}
	return ;
}
int main(){
	struct node *head=NULL;
	head=CreateList(head);
	printf("\n--Before--\n");
	DisplayList(head);
	printf("\n--After--\n");
	traverse(head);
	return 0;
}