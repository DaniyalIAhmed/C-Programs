#include<stdio.h>
#include<stdlib.h>
main(){
    //Program to create 2D array using pointers & summing up rows and columns of it..
    int rows, col, i, j, rsum=0;
	printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &col);
    int csum[col];
    int **ptr;
    ptr = (int**)calloc(rows,sizeof(int*));
    for(i = 0;i<rows;i++){
    	*(ptr+i)=(int*)calloc(col,sizeof(int));
	}
	printf("Enter values:\n");
	for(i=0;i<rows;i++){
		for(j=0;j<col;j++){
			scanf("%d", (*(ptr+i)+j));
			csum[j]=0;
		}
	}
	for(i=0;i<rows;i++){
		rsum=0;
		for(j=0;j<col;j++){
			rsum += *(*(ptr+i)+j);
			csum[j] += *(*(ptr+i)+j);
		}
		printf("Row %d sum: %d\n", i+1, rsum);
	}
	for(i=0;i<col;i++){
		printf("Column %d sum: %d\n", i+1, csum[i]);
	}
}

