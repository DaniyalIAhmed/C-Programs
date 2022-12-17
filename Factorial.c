#include<stdio.h>
int factorial(int);
main(){
    //Recursion Problem: Program to find the factorial of a given number..
    int n, fact;
    printf("Enter any number: ");
    scanf("%d", &n);
    fact = factorial(n);
    printf("Factorial of a number is: %d", fact);
}
int factorial(int n){
	static int fact;
	if(n==1)
	return 1;
	else
		return(n*factorial(n-1));
}
