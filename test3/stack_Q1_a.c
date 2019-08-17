#include<stdio.h>
#include<stdlib.h>

// creating doubly list for stack
typedef struct StructList{
	int data;
	struct StructList *prev,*next;
}List;

//Assuming stack containing integers elements except -1

//structure of stack
typedef struct StructStack{
	List *top,*middle;
	int tot;
}Stack;

Stack *createStack(void);
void Push(Stack **S,int data);
int Pop(Stack **S);
void deleteStack(Stack **S);

int main(void){
	int ch,data;
	Stack *S=createStack();
	while(1){
		printf("\n_____________________________________________________");
		printf("\n1: Push\n2: Pop\n3: Top\n4: Middle\n5: Exit");
		printf("\n_____________________________________________________");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:				
				printf("\nEnter the data for push into stack: ");
				scanf("%d",&data);
				// push data into stack S
				Push(&S,data);
				break;
			case 2:
				// pop data from stack S
				data=Pop(&S);
				if(data!=-1)
					printf("\n\t***Popped Element: %d***",data);
				else
					printf("\n\t***Stack is Empty***");
				break;
			case 3:
				// displays top element of stack S
				if(S->top!=NULL)
					printf("\n\t***Top Element: %d***",S->top->data);
				else
					printf("\n\t***Stack is Empty***");
				break;
			case 4:
				// displays middle of element of stack S in )(1)
				if(S->middle!=NULL)
					printf("\n\t***Middle Element: %d***",S->middle->data);
				else
					printf("\n\t***Stack is Empty***");
				break;
			case 5:
				// delete stack S
				deleteStack(&S);
				if(S==NULL){
					printf("\n\t***Stack is successfully deleted***\n\n");
					exit(0); // exit successfully
				}
				else{
					printf("\n\t***Stack is not deleted***\n\n");
					exit(1); // exit normally unsuccessfully
				}
				break;
			default:
				//for invalid selection of choice
				printf("\n\t***Choose Valid Option***");
		}
	}
}

Stack *createStack(void){
	Stack *S=(Stack *)malloc(sizeof(Stack));
	S->top=NULL;
	S->middle=NULL;
	return S;
}

void Push(Stack **S,int data){
	List *node=(List *)malloc(sizeof(List));
	node->data=data;
	node->next=NULL;
	node->prev=NULL;
	if((*S)->top){
		node->next=(*S)->top;
		(*S)->top->prev=node;
	}
	(*S)->top=node;
	(*S)->tot+=1; // keep track of total elements in a stack S
	if((*S)->tot==1) // for base case
		(*S)->middle=(*S)->top;
	else{
		if((*S)->tot%2!=0){ // except base case
			(*S)->middle=(*S)->middle->prev;
		}
	}
}

int Pop(Stack **S){
	int data;
	if((*S)->top==NULL)
		data=-1;
	else{
		List *temp=(*S)->top;
		data=temp->data;
		(*S)->tot-=1;
		if((*S)->top->next){ // if exist
			(*S)->top=(*S)->top->next;// adjusting top element of stack S
			if((*S)->tot%2==0 && (*S)->tot>0){
				if((*S)->middle->next) // if exist
					(*S)->middle=(*S)->middle->next; // adjusting middle element of stack S
			}
		}
		else{ // if all elements get popped
			(*S)->top=NULL;
			(*S)->middle=NULL;
		}
		free(temp);
	}
	return data;
}


void deleteStack(Stack **S){
	List *temp;
	while((*S)->top){
		temp=(*S)->top;
		(*S)->top=(*S)->top->next;
		free(temp);
	}
	free(*S);
	*S=NULL;
}
