void print(int *arr, int size){
	int i;
	printf("\nThe array elements are: ");
	for(i=0; i<size; i++){
		printf("%d ", *(arr+i));
	}
	printf("\n");
	return;
}

void getArray(int *arr, int size){
	int i;
	printf("\n--Enter elements into the array--\n");
	for(i=0; i<size; i++){
		printf("Enter the next element: ");
		scanf("%d", arr+i);
	}
	printf("\n");
	return;
}