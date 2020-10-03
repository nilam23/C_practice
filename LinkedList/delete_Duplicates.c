#include<stdlib.h>
#include<stdio.h>
#include"myListHeader.h"

struct node *deleteDuplicate(struct node* head){
	struct node *cur, *next;
	cur = head;
	next = NULL;
	while(cur->link){
		if(cur->data == cur->link->data){
			next = cur->link->link;
			free(cur->link);
			cur->link = next;
		}
		else
			cur = cur->link;
	}
	return head;
}

int main(){
	struct node *head = NULL;
	head = CreateList(head);
	printf("--Before removing--\n");
	DisplayList(head);
	head = deleteDuplicate(head);
	printf("--After removing--\n");
	DisplayList(head);
	return 0;
}