void printStack(int *stack, int top){
	int i;
	printf("\nThe stack elements are: ");
	for(i=top; i>=0; i--){
		printf("%d ", *(stack+i));
	}
	printf("\n");
	return;
}