#include<stdio.h>
#include<stdlib.h>
#include "myListHeader.h"
int Occurence(struct node *head, int item){
	struct node *t=head;
	int count=0;
	while(t){
		if(t->data==item)
			count++;
		t=t->link;
	}
	if(count)
		return count;
	else
		return 0;
}
int main(){
	struct node *head=NULL;
	head=CreateList(head);
	DisplayList(head);
	int item;
	printf("Enter an element from the list: ");
	scanf("%d", &item);
	int count=Occurence(head, item);
	if(count)
		printf("%d appeared %d times.\n", item, count);
	else
		printf("%d is not in the list.\n");
	return 0;
}