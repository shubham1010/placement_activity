#include<stdio.h>
#include<stdlib.h>
#include "mergeSort.h"

void input(int **arr,int m ,int n);
void display2D(int **arr,int m,int n);
void snakeSort(int **arr,int m ,int n);

int main(void){
	int **arr,m,n;
	printf("\nEnter the size of 'm' and 'n' : ");
	scanf("%d %d",&m,&n);
	arr= (int **)malloc(sizeof(int)*m);
	
	for(int i=0 ; i<n ; i++)
		*(arr+i)=(int *)malloc(sizeof(int)*n);

	input(arr,m,n);

	printf("\nOriginal 2D array: ");
	display2D(arr,m,n);
	
	snakeSort(arr,m,n);
	printf("\nAfter snakesort: ");
	display2D(arr,m,n);


	free(arr);
	for(int i=0 ; i<n ; i++)
		free(*(arr+i));
}

void snakeSort(int **arr,int m ,int n){
	int tot=m*n;
	int *singleD=(int *)malloc(sizeof(int)*tot);
	int *temp=(int *)malloc(sizeof(int)*tot);
	int k=0;
	for(int i=0 ; i<m ; i++){
		for(int j=0 ; j<n ; j++){
			singleD[k]=arr[i][j];
			k+=1;
		}
	}

	mergeSort(singleD,temp,0,tot-1);
	
	int r=0,c=0,flag=0;

	for(int i=0 ; i<tot ; i++){
		arr[r][c]=singleD[i];
		if((i+1)%n==0){
			r+=1;
			if (flag==1){
				flag=0;
				c-=1;
			}
			else{
				flag=1;
				c+=1;
			}
		}
		if(flag==0)
			c+=1;
		else
			c-=1;
	}

	free(singleD);
	free(temp);
}

void input(int **arr,int m ,int n){
	for(int i=0 ; i<m ; i++){
		printf("\nEnter %d elements for %d row: ",n,i+1);
		for(int j=0 ; j<n ; j++)
			scanf("%d",&arr[i][j]);		
	}
}

void display2D(int **arr,int m,int n){
	printf("\n");
	for(int i=0 ; i<m ; i++){
		for(int j=0 ; j<n ; j++)
			printf("%d ",arr[i][j]);
		printf("\n");
	}
	printf("\n\n");
}
