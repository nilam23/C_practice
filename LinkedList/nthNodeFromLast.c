#include<stdio.h>
#include<stdlib.h>
#include"myListHeader.h"

void findNode(struct node *head, int n){
	if(head == NULL){
		printf("The list is empty.\n");
		return;
	}
	struct node *p, *q;
	p = head;
	q = head;
	int count = 0;
	while(count < n){
		if(!q){
			printf("%d is greater than the length of the list.\n", n);
			return;
		}
		q = q->link;
		count++;
	}
	while(q){
		p = p->link;
		q = q->link;
	}
	printf("Data item of the nth node from last: %d", p->data);
	return;
}

int main(){
	int n;
	struct node *head = NULL;
	head = CreateList(head);
	DisplayList(head);
	printf("Enter the nth position from last: ");
	scanf("%d", &n);
	findNode(head, n);
	return 0;
}