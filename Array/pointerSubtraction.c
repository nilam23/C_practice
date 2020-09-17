#include<stdio.h>

int main(){
    int arr[5] = {1, 2, 3, 4, 5};
    int *p, *q;
    p = &arr[1];
    q = &arr[4];
    printf("The Array elements are:\n");
    for(int i = 0; i < 5; i++)
        printf("%d ", arr[i]);
    printf("\n\nThe no of elements between p and q is %d", q-p+1);
    return 0;
}