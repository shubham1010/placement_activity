
typedef struct StructLinkedList{
	int data;
	struct StructLinkedList *next;
}List;

typedef struct StructQueue{
	List *front,*rear;
}Queue;


Queue *createQueue(void);
int isEmptyQueue(Queue *Q);
void EnQueue(Queue *Q,int data);
int DeQueue(Queue *Q);
void deleteQueue(Queue **Q);


Queue *createQueue(void){
	Queue *Q=(Queue *)malloc(sizeof(Queue));
	Q->front=Q->rear=NULL;
	return Q;
}

void EnQueue(Queue *Q,int data){
	List *node=(List *)malloc(sizeof(List));
	node->data=data;
	node->next=NULL;
	if(Q->rear){
		Q->rear->next=node;
	}
	Q->rear=node;
	if(Q->front==NULL)
		Q->front=Q->rear;
	Q->rear->next=Q->front;
}

int DeQueue(Queue *Q){
	if(Q->rear){
		List *temp=Q->front;
		int t=temp->data;
		if(Q->front->next && Q->front->next!=Q->front){
			Q->front=Q->front->next;
			Q->rear->next=Q->front;
		}
		else
			Q->front=Q->rear=NULL;
		free(temp);
		return t;
	}
	else
		return -1;
}

int isEmptyQueue(Queue *Q){
	return (Q->front==NULL);
}

void deleteQueue(Queue **Q){
	List *temp;
	if((*Q)->front==(*Q)->rear)
		free((*Q)->front);
	else{
		(*Q)->rear->next=NULL;
		while((*Q)->front){
			temp=(*Q)->front;
			(*Q)->front=(*Q)->front->next;
			free(temp);
		}
		free((*Q)->front);
	}
	*Q=NULL;
}

void displayCirQueue(Queue *Q){
	if(Q->front){
		List *temp=Q->front;
		printf("\nPrinting Circular Queue: ");
		while(1){
			printf("%d ",temp->data);
			temp=temp->next;
			if(temp==Q->front)
				break;
		}
	}
	else
		printf("\n\t***Unable to print Queue is Empty***");
}
