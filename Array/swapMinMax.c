#include<stdio.h>
#include<stdlib.h>

void findEtremes(int *arr, int n, int *minIndex, int *maxIndex)
{
	int i;
	int min=*arr, max=*arr;
	for(i=0; i<n; i++)
	{
		if(*(arr+i) <= min){
			min = *(arr+i);
			*minIndex = i;
		}
		if(*(arr+i) >= max){
			max = *(arr+i);
			*maxIndex = i;
		}
	}
}

void swap(int *arr, int n, int minIndex, int maxIndex)
{
	int temp=*(arr+minIndex);
	*(arr+minIndex)=*(arr+maxIndex);
	*(arr+maxIndex)=temp;

}

void process(int *arr, int n)
{
	int minIndex, maxIndex;
	int i;
	findEtremes(arr, n, &minIndex, &maxIndex);
	printf("The minimum value in the array: %d\n", *(arr+minIndex));
	printf("The maximum value in the array: %d\n", *(arr+maxIndex));
	swap(arr, n, minIndex, maxIndex);
	printf("New array elements are: ");
	for(i=0; i<n; i++)
	{
		printf("%d ", *(arr+i));
	}	
}

int main()
{
	int n, i;
	printf("Enter the no of elements in the array: ");
	scanf("%d", &n);
	int *arr;
	arr = (int *)calloc(n, sizeof(int));
	if(arr == NULL){
		printf("Insufficient space in the heap.\n");
		exit(1);
	}
	printf("--Enter the array elements--\n");
	for(i=0; i<n; i++)
	{
		printf("Enter the %dth element: ", i);
		scanf("%d", arr+i);
	}
	printf("The array is: ");
	for(i=0; i<n; i++)
	{
		printf("%d ", *(arr+i));
	}
	printf("\n");

	process(arr, n);
	while(1){
		int c;
		int num;
		printf("\nDo you want to enter more elements in the array?\n0(NO)/1(YES):");
		scanf("%d", &c);
		switch (c){
			case 0:
				return 0;
			case 1:
				printf("How many more elements do you want to enter?\n");
				scanf("%d", &num);
				arr = (int *)realloc(arr, (n+num)*sizeof(int));
				for(i=n; i<(n+num); i++)
				{
					printf("Enter the %dth element: ");
					scanf("%d", arr+i);
				}
				printf("The array is now: ");
				for(i=0; i<(n+num); i++)
				{
					printf("%d ", *(arr+i));
				}
				printf("\n");
				process(arr, (n+num));
				break;
			default:
				printf("Invalid choice.\n");
				break;
			}
	}
	free(arr);
	return 0;
}