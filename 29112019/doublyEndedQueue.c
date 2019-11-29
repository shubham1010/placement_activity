#include<stdio.h>
#include<stdlib.h>

typedef struct DoublyLinkedList{
	int data;
	struct DoublyLinkedList *prev,*next;
}DList;

typedef struct StructDoubleEndedQueue{
	DList *front,*rear;
}DEQueue;

/*
	Operation to define for double ended queue
	1)EnQueueFront(&Q,data)
	2)EnQueueBack(&Q,data)
	3)DeQueueFront(&Q)
	4)DeQueueBack(&Q)
	5)isEmptyQueue(Q)
*/


void deleteDoubleEndedQueue(DEQueue **Q);
DEQueue *createDoubleEndedQueue(void);
void EnQueueFront(DEQueue **Q,int data);
void EnQueueBack(DEQueue **Q,int data);
int DeQueueFront(DEQueue **Q);
int DeQueueBack(DEQueue **Q);
int isEmptyQueue(DEQueue *Q);

int main(void){
	int ch,data;
	DEQueue *Q=createDoubleEndedQueue();
	while(1){
		printf("\n1: EnQueue Front\n2: EnQueue Back\n3: DeQueue Front\n4: DeQueue Back\n5: isEmptyQueue\n6: DisplayFront\n7: DisplayBack\n8: Exit");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		if(ch==8)
			break;
		switch(ch){
			
			case 1:
				printf("\nEnter data for Front EnQueue: ");
				scanf("%d",&data);
				EnQueueFront(&Q,data);
				break;
			
			case 2:
				printf("\nEnter data for Back EnQueue: ");
				scanf("%d",&data);
				EnQueueBack(&Q,data);
				break;
			
			case 3:
				data=DeQueueFront(&Q);
				if(data!=-1)
					printf("\n\t\t***Front DeQueue Element: %d***",data);
				else
					printf("\n\t\t**Doubly Ended Queue is already empty***");
				break;
			
			case 4:
				data=DeQueueBack(&Q);
				if(data!=-1)
					printf("\n\t\t***Back DeQueue Element: %d***",data);
				else
					printf("\n\t\t**Doubly Ended Queue is already empty***");
				break;

			case 5:
				if(isEmptyQueue(Q))
					printf("\n\t\t***Double Ended Queue is Empty***");
				else
					printf("\n\t\t***Double Ended Queue is not Empty***");
				break;

			case 6:
				if(Q->front)
					printf("\n\t\t***Front Data= %d***",Q->front->data);
				else
					printf("\n\t\t**Doubly Ended Queue is already empty***");
				break;

			case 7:
				if(Q->rear)
					printf("\n\t\t***Back Data= %d***",Q->rear->data);
				else
					printf("\n\t\t**Doubly Ended Queue is already empty***");
				break;
			default:
				printf("\n\t\t***Please select the right option***");
		}
	}
	deleteDoubleEndedQueue(&Q);
	printf("\n\t\t***Double Ended Queue Successfully Deleted***");
}

void deleteDoubleEndedQueue(DEQueue **Q){
	DList *f=(*Q)->front,*r=(*Q)->rear;
	
	while(f!=r && f!=NULL && r!=NULL){
		(*Q)->front=(*Q)->front->next;
		free(f);
		(*Q)->front->prev=NULL;
		f=(*Q)->front;

		(*Q)->rear=(*Q)->rear->prev;
		free(r);
		(*Q)->rear->next=NULL;
		r=(*Q)->rear;
	}
	if(f)
		free(f);
	*Q=NULL;
}

DEQueue *createDoubleEndedQueue(void){
	DEQueue *Q=(DEQueue *)malloc(sizeof(DEQueue));
	Q->front=Q->rear=NULL;
	return Q;
}

void EnQueueFront(DEQueue **Q,int data){
	DList *newNode=(DList *)malloc(sizeof(DList));
	newNode->data=data;
	newNode->prev=NULL;
	newNode->next=NULL;

	if(isEmptyQueue(*Q)){
		(*Q)->front=newNode;
		(*Q)->rear=(*Q)->front;
	}
	else{
		newNode->next=(*Q)->front;
		(*Q)->front->prev=newNode;
		(*Q)->front=newNode;
	}
}

void EnQueueBack(DEQueue **Q,int data){
	DList *newNode=(DList *)malloc(sizeof(DList));
	newNode->data=data;
	newNode->prev=NULL;
	newNode->next=NULL;

	if(isEmptyQueue(*Q)){
		(*Q)->front=newNode;
		(*Q)->rear=(*Q)->front;
	}
	else{
		(*Q)->rear->next=newNode;
		newNode->prev=(*Q)->rear;
		(*Q)->rear=(*Q)->rear->next;
	}
}

int DeQueueFront(DEQueue **Q){
	int data=-1;
	if(!isEmptyQueue(*Q)){
		DList *temp=(*Q)->front;
		data=temp->data;
		if((*Q)->front->next)
			(*Q)->front=(*Q)->front->next;
		else
			(*Q)->front=(*Q)->rear=NULL;
		if((*Q)->front)
			(*Q)->front->prev=NULL;
		free(temp);
	}
	return data;	
}

int DeQueueBack(DEQueue **Q){
	int data=-1;
	if(!isEmptyQueue(*Q)){
		DList *temp=(*Q)->rear;
		data=temp->data;
		if((*Q)->rear->prev)
			(*Q)->rear=(*Q)->rear->prev;
		else
			(*Q)->front=(*Q)->rear=NULL;
		if((*Q)->rear)
			(*Q)->rear->next=NULL;
		free(temp);
	}
	return data;
}

int isEmptyQueue(DEQueue *Q){
	return (Q->front==NULL);
}
