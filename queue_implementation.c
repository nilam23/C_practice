#include<stdio.h>
#include<stdlib.h>
#define max 10

int queue[max];
int front=0, rear=0;

void enQueue(int item){
	rear=(rear+1) % max;
	if(front==rear){
		printf("Overflow: Queue is full.\n");
		if(rear==0)
			rear=max-1;
		else
			rear=rear-1;
		return;
	}
	else{
		queue[rear]=item;
		return;
	}
}

int deQueue(){
	int item;
	if(front==rear){
		return -1;
	}
	else{
		front=(front+1) % max;
		item=queue[front];
		return item;
	}
}

void printQueue(){
	printf("Current Queue elements are:\n");
	for(int i=front+1; i<=rear; i++)
	{
		printf("%d\t", queue[i]);
	}
	printf("\n");
}

int main()
{
	int choice, item, deleted_item;
	while(1){
		printf("To insert (1) or to delete (2) an element?\n");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("Enter an element to be inserted: ");
				scanf("%d", &item);
				enQueue(item);
				printQueue();
				break;
			case 2:
				deleted_item=deQueue();
				if(deleted_item==-1){
					printf("Underflow:Queue is empty.\n");
					break;
				}
				else{
					printf("The element deleted from the beginning of the queue: %d\n", deleted_item);
					printQueue();
					break;
				}
			default:
				printf("Enter either 1 or 2\n");
				break;
		}
	}
	return 0;
}