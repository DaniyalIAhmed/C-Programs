#include<stdio.h>
void swap(int*, int*);
main(){
    //Program to swap values of two variables passed by reference
    int n1, n2;
    printf("Enter first value: ");
    scanf("%d", &n1);
    printf("Enter second value: ");
    scanf("%d", &n2);
    printf("Your entered these numbers: %d, %d\n", n1, n2);
    swap(&n1, &n2);
    printf("Your values after swap: %d, %d", n1, n2);
}
void swap(int *ptr1, int *ptr2){
	int temp;
	temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}
