#include<stdio.h>
#include<stdlib.h>

int main(){
	int n, i=0;
	scanf("%d", &n);
	int a[n], b[n], c[n];
	while(i<n && (scanf("%d", (a+i++)))==1);
	i=0;
	while(i<n && (scanf("%d", (b+i++)))==1);
	for(i=0; i<n; i++){
		c[i]=a[i]+b[i];
		printf("%d ", *(c+i));
	}
	return 0;
}