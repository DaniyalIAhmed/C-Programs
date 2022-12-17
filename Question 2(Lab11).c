#include<stdio.h>
void manual_strcpy(char*, char*);
main(){
    //Program to copy string 2 to string 1 manually
    char str1[100], str2[50];
    printf("Enter string 1: ");
    gets(str1);
    printf("\nEnter string 2: ");
    gets(str2);
    printf("You entered these strings: %s, %s\n", str1, str2);
    manual_strcpy( str1, str2);
    printf("String 1: %s\n", str1);
    printf("String 2: %s", str2);
}
void manual_strcpy(char* str1, char* str2){
	int i, j;
	for(i=0;*(str1+i)!='\0';i++){
		
	}
	for(j=0;*(str2+j)!='\0'; i++, j++){
		*(str1+i)= *(str2+j);
	}
	*(str1+i)='\0';
}
