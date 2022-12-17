#include<stdio.h>
main(){
    //Program to create array of n elements using only pointers
    int n, i, sum=0;
    printf("Enter number of elements to be stored in an array: ");
    scanf("%d", &n);
    int *ptr;
    ptr = (int *)calloc(n,sizeof(int));
    printf("Enter values:\n");
    for(i = 0;i<n;i++){
    	scanf("%d", (ptr+i));
	}
	for(i=0;i<n;i++){
		sum += *(ptr+i);
	}
	printf("The sum is found to be: %d", sum);
}

