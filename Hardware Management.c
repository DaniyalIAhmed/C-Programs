#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct inventory{
	int record;
	char tool[20];
	int quantity;
	float cost;	
}in, inc;
void input(void);
void list(void);
void del(void);
void up(void);
main(){
	int choice;char ch;
	b:
	system("cls");
    printf("Welcome to Hardware Management System.\nSelect from below:\n1.Input\n2.Print List\n3.Delete Record\n4.Update Record\n5.Exit\n");
    a:
	scanf("%d", &choice);
    switch(choice){
    	case 1:
    		input();
    		break;
    	case 2:
    		list();
    	    break;
    	case 3:
    		del();
    		break;
    	case 4:
    		up();
    		break;
    	case 5:
    		goto c;
    	default:
    		printf("Invalid choice :( Enter again: ");
    		goto a;
	}
	printf("Want to do more? Press Y: ");
	scanf(" %c", &ch);
	if(ch == 'Y' || ch=='y'){
		system("cls");
		goto b;
	}
	else
	c:
	exit(1);
}
void input(void){
	FILE* fp;int i;
    fp = fopen("hardware.txt", "w");
    for(i =0;i<2;i++){
    	printf("Enter Record# ");
    	fflush(stdin);
    	scanf("%d", &in.record);
    	printf("\nEnter Name: ");
    	fflush(stdin);
    	gets(in.tool);
    	printf("\nEnter Quantity: ");
    	fflush(stdin);
    	scanf("%d", &in.quantity);
    	fflush(stdin);
		printf("\nEnter Cost: ");
    	scanf("%f", &in.cost);
    	fflush(stdin);
    	fwrite(&in, 1, sizeof(struct inventory), fp);
	}
	fclose(fp);
}
void list(void){
	FILE* fp;
    fp = fopen("hardware.txt", "r");
    while(fread(&inc,sizeof(struct inventory),1,fp)!=NULL){
    	printf("\nRecord: %d\tTool Name: %s\tQuantity: %d\tCost: %.2f\n", inc.record, inc.tool, inc.quantity, inc.cost);
	}
	fclose(fp);
}
void del(void){
	FILE *fp, *fp1;int rec;
	fp = fopen("hardware.txt", "r");
	fp1= fopen("hardware1.txt", "w");
	printf("Enter Record Number of tool to be deleted: ");
	scanf("%d", &rec);
	while(fread(&inc, 1, sizeof(struct inventory), fp)!=NULL){
		if(inc.record==rec){
		}
		else{
			fwrite(&inc, 1, sizeof(struct inventory), fp1);
		}
	}
	fclose(fp);
	fclose(fp1);
	fp = fopen("hardware.txt", "w");
	fp1= fopen("hardware1.txt", "r");
	while(fread(&inc, 1, sizeof(struct inventory), fp1)!=NULL){
		fwrite(&inc, 1, sizeof(struct inventory), fp);
	}
	fclose(fp);
	fclose(fp1);
}
void up(void){
	FILE *fp;
	fp = fopen("hardware.txt", "a");
    printf("Enter Record# ");
    fflush(stdin);
    scanf("%d", &in.record);
    printf("\nEnter Name: ");
    fflush(stdin);
    gets(in.tool);
    printf("\nEnter Quantity: ");
    fflush(stdin);
    scanf("%d", &in.quantity);
    fflush(stdin);
	printf("\nEnter Cost: ");
    scanf("%f", &in.cost);
    fflush(stdin);
    fwrite(&in, 1, sizeof(struct inventory), fp);
    fclose(fp);
}
