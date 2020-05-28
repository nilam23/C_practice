#include<stdio.h>
void tofh(int n, char src, char tmp, char dst){
	if(n == 1){
		printf("\t-Move disk %d from %c to %c.\n", n, src, dst);
		return;
	}
	tofh(n-1, src, dst, tmp);
	printf("\t-Move disk %d from %c to %c.\n", n, src, dst);
	tofh(n-1, tmp, src, dst);
	return;
}
int main(){
	char src = 'A', tmp = 'B', dst = 'C';
	int n;
	printf("Enter the total no of disks: ");
	scanf("%d", &n);
	printf("The sequence of moving the disks from source A to destination C is:\n");
	tofh(n, src, tmp, dst);
	return 0;
}