#include<stdio.h>
#include<stdlib.h>
#define	row1 2
#define col1 2
#define row2 2
#define col2 3

int main()
{
	int m1[row1][col1], m2[row2][col2], m3[row1][col2];
	int i, j, k;

	printf("Enter the elements in matrix 1:\n");
	for(i=0; i<row1; i++)
		for(j=0; j<col1; j++)
			scanf("%d", &m1[i][j]);
	printf("Enter the elements in matrix 2:\n");
	for(i=0; i<row2; i++)
		for(j=0; j<col2; j++)
			scanf("%d", &m2[i][j]);

	printf("Matrix 1:\n");
	for(i=0; i<row1; i++)
	{
		for(j=0; j<col1; j++)
		{
			printf("%d\t", m1[i][j]);
		}
		printf("\n");
	}
	printf("Matrix 2:\n");
	for(i=0; i<row2; i++)
	{
		for(j=0; j<col2; j++)
		{
			printf("%d\t", m2[i][j]);
		}
		printf("\n");
	}

	for(i=0; i<row1; i++)
	{
		for(j=0; j<col2; j++)
		{
			m3[i][j]=0;
			for(k=0; k<col1; k++)
			{
				m3[i][j] += m1[i][k] * m2[k][j];
			}
		}
	}

	printf("After Matrix Multiplication, the resultant matrix is:\n");
	for(i=0; i<row1; i++)
	{
		for(j=0; j<col2; j++)
		{
			printf("%d\t", m3[i][j]);
		}
		printf("\n");
	}
	return 0;
}