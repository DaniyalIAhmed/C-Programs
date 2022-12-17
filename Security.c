#include<stdio.h>
void encrypt(char* ptr){
	int i;
	for(i=0;*(ptr+i)!='\0';i++){
		if(*(ptr+i)>=65 && *(ptr+i)<=90){
			*(ptr+i)+=2;
		}
		else if(*(ptr+i)>=97 && *(ptr+i)<=122){
			*(ptr+i)+=2;
		}
	}
	FILE *fp;
	fp = fopen("safe.txt","w");
	fwrite(ptr, 1, sizeof(ptr), fp);
	fclose(fp);
	printf("After Encryption the text will look like this: ");
	puts(ptr);
}
void decrypt(char* ptr){
	int i, j;
	printf("Press 1 to read from a file or 2 to read string: ");
	scanf("%d", &j);
	if(j==2){
	for(i=0;*(ptr+i)!='\0';i++){
		if(*(ptr+i)>=65 && *(ptr+i)<=90){
			*(ptr+i)-=2;
		}
		else if(*(ptr+i)>=97 && *(ptr+i)<=122){
			*(ptr+i)-=2;
		}
	}
	FILE *fp;
	fp = fopen("safe.txt","w");
	fwrite(ptr, 1, sizeof(ptr), fp);
	fclose(fp);
    }
    else if(j==1){
    	FILE *fp;
    	fp = fopen("safe.txt", "r");
    	if(fp == NULL)
    	printf("File does not exists!");
    	else{
    		fread(ptr, 1, sizeof(ptr), fp);
    		for(i=0;*(ptr+i)!='\0';i++){
		        if(*(ptr+i)>=65 && *(ptr+i)<=90){
			    *(ptr+i)-=2;
		        }
		        else if(*(ptr+i)>=97 && *(ptr+i)<=122){
			    *(ptr+i)-=2;
		        }
	        }
		}
	}
	printf("After Decryption: ");
	puts(ptr);
}
main(){
	char ptr[100];int choice;
	printf("Enter any sentence: ");
	gets(ptr);
	printf("Do you want to encrypt or decrypt the message?\n");
	scanf("%d", &choice);
	if(choice==1)
	encrypt(ptr);
	else if(choice==2)
	decrypt(ptr);
}
