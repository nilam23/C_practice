#include<stdio.h>
#include<stdlib.h>
#include"myListHeader.h"

void findNode1(struct node *head, int n){
	printf("\n--METHOD 1--\n");
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

void findNode2(struct node *head, int n){
	printf("\n--METHOD 2--\n");
	if(head == NULL){
		printf("The list is empty.\n");
		return;
	}
	struct node *p = head;
	int len = 0, pos;
	while(p){
		len++;
		p = p->link;
	}
	if(n > len){
		printf("%d is larger than the length of the list.\n", n);
		return;
	}
	pos = len - n + 1;
	p = head;
	while(pos-- > 1)
		p = p->link;
	printf("Data item of the target node is: %d\n", p->data);
	return;
}

int main(){
	int n, choice;
	struct node *head = NULL;
	head = CreateList(head);
	while(1){
		printf("\n\n");
		DisplayList(head);
		printf("Choose either method 1 or 2.\n");
		printf("Your choice: ");
		scanf("%d", &choice);
		printf("Enter the nth position from last: ");
		scanf("%d", &n);
		switch(choice){
			case 1:
				findNode1(head, n);
				break;
			case 2:
				findNode2(head, n);
				break;
			default:
				printf("\n--EXITING--\n");
				exit(1);
		}
	}
	return 0;
}