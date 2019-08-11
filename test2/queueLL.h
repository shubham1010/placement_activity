//#include<stdio.h>
//#include<stdlib.h>


typedef struct StructLinkedList{
	char pname[50];
	float st,ft;
	struct StructLinkedList *next;
}List;

typedef struct StructQueue{
	List *front,*rear;
}Queue;


Queue *createQueue(void);
int isEmptyQueue(Queue *Q);
void EnQueue(Queue *Q,List *node);
char *DeQueue(Queue *Q);
void deleteQueue(Queue **Q);


Queue *createQueue(void){
	Queue *Q=(Queue *)malloc(sizeof(Queue));
	Q->front=Q->rear=NULL;
	return Q;
}

void EnQueue(Queue *Q,List *node){

	if(Q->rear){
		Q->rear->next=node;
	}
	Q->rear=node;
	if(Q->front==NULL)
		Q->front=Q->rear;
}

char *DeQueue(Queue *Q){
	if(Q->rear){
		List *temp=Q->front;
		char *pname=(char *)malloc(sizeof(char)*10);
		strcpy(pname,temp->pname);
		if(Q->front->next)
			Q->front=Q->front->next;
		else
			Q->front=Q->rear=NULL;
		free(temp);
		return pname;
	}
	else
		return "-1";
}

int isEmptyQueue(Queue *Q){
	return (Q->front==NULL);
}

void deleteQueue(Queue **Q){
	List *temp;
	while((*Q)->front){
		temp=(*Q)->front;
		(*Q)->front=(*Q)->front->next;
		free(temp);
	}
	free((*Q)->front);
	*Q=NULL;
}
