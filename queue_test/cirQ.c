#include<stdio.h>
#include<stdlib.h>
#include "queueWithSinglyLL.h"

int main(void){
	int ch,ele,data;
	Queue *Q=createQueue();
	while(1){
		printf("\n_________________________________________________________\n");
		printf("\n1: EnQueue\n2: DeQueue\n3: Front\n4: Rear\n5: Display\n6:IsEmpty\n7: Exit");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		printf("_________________________________________________________");
		switch(ch){
			case 1:
				printf("\nEnter your data: ");
				scanf("%d",&data);
				EnQueue(Q,data);
				break;

			case 2:
				ele=DeQueue(Q);
				if(ele!=-1)
					printf("\n\t***DeQueue Element: %d***",ele);	
				else
					printf("\n\t***Queue is Empty, No element for DeQueue***");
				break;

			case 3:
				if(Q->front)
					printf("\n\t***Queue Front= %d***",Q->front->data);
				else
					printf("\n\t***Queue is Empty***");
				break;

			case 4:
				if(Q->rear)
					printf("\n\t***Queue Rear= %d***",Q->rear->data);
				else
					printf("\n\t***Queue is Empty***");
				break;
			case 5:
				displayCirQueue(Q);
				break;
			case 6:
				if(isEmptyQueue(Q))
					printf("\n\t***Queue is Empty***");
				else
					printf("\n\t***Queue is not Empty***");
				break;
			case 7:
				deleteQueue(&Q);
				if(Q==NULL)
					printf("\n\t***Queue is Successfully deleted..!!***\n\n");
				exit(0);
				break;
			default:
				printf("\n\t***Please enter valid options..!!***");
		}

	}
}
