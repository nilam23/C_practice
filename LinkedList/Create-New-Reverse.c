#include<stdlib.h>
#include<stdio.h>
#include"myListHeader.h"
struct node *head2=NULL;
void CreateNew(struct node *t){
	if(t){
		CreateNew(t->link);
		if(head2==NULL){
			head2=AddAtBeginning(head2, t->data);
		}
		else{
			head2=AddAtEnd(head2, t->data);
		}
	}
	return;
}
int main(){
	struct node *head1=NULL;
	printf("\n--CREATE LIST 1--\n");
	head1=CreateList(head1);
	printf("\n--LIST 1--\n");
	DisplayList(head1);
	CreateNew(head1);
	printf("\n--After Creating the LIST 2--\n");
	printf("\n--LIST 1--\n");
	DisplayList(head1);
	printf("\n--LIST 2--\n");
	DisplayList(head2);
	return 0;
}