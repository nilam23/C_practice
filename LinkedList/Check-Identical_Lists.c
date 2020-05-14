#include<stdio.h>
#include<stdlib.h>
#include"myListHeader.h"
int Check(struct node *head1, struct node *head2){
	struct node *t1=head1, *t2=head2;
	while(t1){
		if(t1->data == t2->data){
			t1=t1->link;
			t2=t2->link;
		}
		else
			return 0;
	}
	return 1;
}
int main(){
	struct node *head1=NULL, *head2=NULL;
	printf("\n--Create List1--\n");
	head1=CreateList(head1);
	printf("\n--Create List2--\n");
	head2=CreateList(head2);
	printf("\n");
	int count1=CountNodes(head1);
	int count2=CountNodes(head2);
	if(count1!=count2)
		printf("Not Identical.\n");
	else{
		if(Check(head1, head2))
			printf("Identical.\n");
		else
			printf("Not Identical.\n");
	}
	return 0;
}