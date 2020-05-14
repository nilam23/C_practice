#include<stdio.h>
#include<stdlib.h>
#include"myListHeader.h"
struct node *Copy(struct node *head1, struct node *head2){
	struct node *t1=head1, *t2=head2, *new;
	while(t1){
		new=(struct node *)malloc(sizeof(struct node));
		new->data=t1->data;
		new->link=NULL;
		if(head2==NULL){
			head2=new;
			t2=head2;
		}
		else{	
			t2->link=new;
			t2=t2->link;
		}
		t1=t1->link;
	}
	return head2;
}
int main(){
	struct node *head1=NULL, *head2=NULL;
	printf("\n--CREATE LIST 1--\n");
	head1=CreateList(head1);
	printf("\n--LIST 1--\n");
	DisplayList(head1);
	head2=Copy(head1, head2);
	printf("\n--LIST 2--\n");
	DisplayList(head2);
	return 0;
}