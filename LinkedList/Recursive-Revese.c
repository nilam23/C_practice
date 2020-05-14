#include<stdio.h>
#include<stdlib.h>
#include "myListHeader.h"
struct node *head=NULL;
void Reverse(struct node *prev, struct node *curr){
	if(curr){
		Reverse(curr, curr->link);
		curr->link=prev;
	}
	else
		head=prev;
}
int main(){
	head=CreateList(head);
	printf("\n--Before--\n");
	DisplayList(head);
	Reverse(NULL, head);
	printf("\n--After--\n");
	DisplayList(head);
	return 0;
}