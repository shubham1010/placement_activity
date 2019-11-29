#include<stdio.h>
#include<stdlib.h>

#include "doublyEndedQueue.h"

int *allocate(int size);
void accept(int *arr,int size);
void display(int *arr,int size);
void maxSlidingWindow(int *A,int n,int w,int *B);

int main(void){
	int *A,*B,n,w;

	printf("\nEnter the size of the array: ");
	scanf("%d",&n);
	A=allocate(n);
	accept(A,n);
	printf("\nYour Entered Array: ");
	display(A,n);

	printf("\nEnter your window size: ");
	scanf("%d",&w);
	if(w<=n && w>=0){

		B=allocate(n);
		maxSlidingWindow(A,n,w,B);
		
		printf("\nAll maximum numbers in between window size %d are: \n",w);
		display(B,n-(w-1));

		free(B);
	}
	else
		printf("\n\t\t***Please enter the window size in between 0 and size of array both including***");
	free(A);
	printf("\n\n");
}

int *allocate(int size){
	int *arr;
	arr=(int *)malloc(sizeof(int)*size);
	return arr;
}

void accept(int *arr,int size){
	for(int i=0 ; i<size ; i++)
		scanf("%d",&arr[i]);
}

void display(int *arr,int size){
	for(int i=0 ; i<size ; i++)
		printf("%d ",arr[i]);
}

void maxSlidingWindow(int *A,int n,int w,int *B){
	DEQueue *Q=createDoubleEndedQueue();

	for(int i=0 ; i<w ; i++){
		while(!isEmptyQueue(Q) && A[i] >= A[Q->rear->data])
			DeQueueBack(&Q);
		EnQueueBack(&Q,i);
	}

	for(int i=w ; i<n ; i++){
		B[i-w]=A[Q->front->data];
		while(!isEmptyQueue(Q) && A[i]>=A[Q->rear->data])
			DeQueueBack(&Q);
		while(!isEmptyQueue(Q) && Q->front->data <= i-w)
			DeQueueFront(&Q);
		EnQueueBack(&Q,i);
	}
	B[n-w] = A[Q->front->data];
}
