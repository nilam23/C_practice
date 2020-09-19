#include<stdio.h>
#include<stdlib.h>
#include "myListHeader.h"

struct node * selectionSort01(struct node *head){
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

struct node * selectionSort02(struct node *head){
	struct node *r, *s, *p, *q, *temp;
	for(r=p=head; p->link; r=p, p=p->link){
		for(s=q=p->link; q; s=q, q=q->link){
			if(q->data < p->data){
				temp = p->link;
				p->link = q->link;
				q->link = temp;
				if(p != head)
					r->link = q;
				else
					head = q;
				s->link = p;
				temp = p;
				p = q;
				q = temp;
			}
		}
	}
	return head;
}

int main(){
	int choice;
	struct node *head = NULL;
	head = CreateList(head);
	DisplayList(head);
	printf("1. Selection Sort by exchanging data.\n");
	printf("2. Selection Sort by rearranging link.\n");
	printf("3. Exit.\n");
	while(1){
		printf("Your choice: ");
		scanf("%d", &choice);
		switch(choice){
		case 1:
			head = selectionSort01(head);
			printf("\n--After Selection Sort--\n");
			DisplayList(head);
			break;
		case 2:
			head = selectionSort02(head);
			printf("\n--After Selection Sort--\n");
			DisplayList(head);
			break;
		case 3:
			printf("\n\n--EXITING--\n");
			exit(0);
		default:
			printf("Wrong choice.\n");
			break;
	}
	}
	return 0;
}