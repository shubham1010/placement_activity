#include<stdio.h>
#include<stdlib.h>
#include "mergeSort.h"

long int **allocateSize(int m,int n);
long int **acceptInput(long int **matrix,int m,int n);
void displayInput(long int **matrix,int m,int n);
long int **strictOrder(long int **matrix,int m,int n);

int main(void){
	int m,n;
	long int **matrix;
	printf("\nEnter the value of m(rows) and n(columns): ");
	scanf("%d %d",&m,&n);
	matrix=allocateSize(m,n);
	if(matrix)
		printf("\nMemory is successfully allocated");
	else
		printf("\nSize of not allocated..!!");
	printf("\n\n");
	matrix=acceptInput(matrix,m,n);
	
	printf("\nBefore Sorting: ");
	displayInput(matrix,m,n);
	
	matrix=strictOrder(matrix,m,n); // get require two dimensional array
	
	printf("\nAfter Sorting: ");
	displayInput(matrix,m,n);
	printf("\n\n");
}	

long int **strictOrder(long int **matrix,int m,int n){
	long int *temp=(long int *)malloc(sizeof(int)*n);
	for(int i=0 ; i<m ; i++)
		mergeSort(*(matrix+i),temp,0,n-1); // sort each row
	
	for(int i=0 ; i<m-1 ; i++){ // to satisfy strict condition
		for(int j=0 ; j<m-1 ; j++){
			if(*(*(matrix+j)+0) > *(*(matrix+j+1)+0)){
				temp=*(matrix+j);
				*(matrix+j)=*(matrix+j+1);
				*(matrix+j+1)=temp;
			}
				
		}
	}
	return matrix;
}
long int **allocateSize(int m,int n){ //allocating memory
	long int **matrix=(long int **)malloc(sizeof(long int)*m);
	for(int i=0 ; i<m ; i++){
		*(matrix+i)=(long int *)malloc(sizeof(long int)*n);
	}
	return matrix;
}

long int **acceptInput(long int **matrix,int m,int n){ // accepting the input
	for(int i=0 ; i<m ; i++){
		printf("\nEnter the %d elements of row: %d\n",n,i+1);
		for(int j=0 ; j<n ; j++){
			scanf("%ld",&(*(*(matrix+i)+j)));
		}
	}
	return matrix;
}

void displayInput(long int **matrix,int m,int n){
	printf("\nYour entered matrix:\n");
	for(int i=0 ; i<m ; i++){
		for(int j=0 ; j<n ; j++){
			printf("%ld ",*(*(matrix+i)+j));
		}
		printf("\n");
	}
}
