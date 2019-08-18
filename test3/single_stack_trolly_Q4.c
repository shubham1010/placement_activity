#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// creating singly list for stack
typedef struct StructList{
	char data;
	struct StructList *next;
}List;


//structure of stack
typedef struct StructStack{
	List *top;
}Stack;

Stack *createStack(void);
void Push(Stack **S,char data);
char Pop(Stack **S);
int isEmptyStack(Stack *S);
void deleteStack(Stack **S);
int isValidPermutaion(char *n1,char *n2);

int main(int argc,char *argv[]){
	if(argc!=3){
		printf("\nPlease pass <executable> <original number> <permuutaed number>");
		exit(0);
	}

	if(isValidPermutaion(argv[1],argv[2]))
		printf("\n\n\t\t***Valid Permutation***");
	else
		printf("\n\n\t\t***Invalid Permutation***");

	printf("\n\n");
}

int isValidPermutaion(char *n1,char *n2){
	printf("\nOriginal Number: %s",n1);
	printf("\nPermuted Number: %s\n",n2);
	if(strlen(n1)!=strlen(n2)) // if lengths are different then they are not same means invalid
		return 0;
	Stack *S=createStack(); // creating stack
	int i=0,j=0;
	while(n1[i]!='\0'){
		while(n2[j]!=n1[i] && n1[i]!='\0'){
			Push(&S,n1[i]); //push until we match with permuted digit
			printf("\n\tPush(S,%c)",n1[i]);
			i+=1;
		}
		if(n1[i]!='\0'){
			Push(&S,n1[i]); // push permuted digit
			printf("\n\tPush(S,%c)",n1[i]);
		}
		while(!isEmptyStack(S)){ // checks while stack is not empty
			if(S->top->data==n2[j]){ // check stack of top's data and j'th permuted digit are same
				// if same pop from stack
				printf("\n\tPop(S): %c",Pop(&S));
				j+=1; // goes to next permuted digit
			}
			else
				break;
		}
		i+=1; // goes to next original digit;
	}
	if(isEmptyStack(S)) // checks stack empty or not
		return 1; // if empty then permutation number is valid
	else{
		deleteStack(&S);
		return 0; // permutation number is invalid
	}
}

int isEmptyStack(Stack *S){
	return (S->top==NULL);
}

Stack *createStack(void){
	Stack *S=(Stack *)malloc(sizeof(Stack));
	S->top=NULL;
	return S;
}

void Push(Stack **S,char data){
	List *node=(List *)malloc(sizeof(List));
	node->data=data;
	node->next=NULL;
	if((*S)->top){
		node->next=(*S)->top;
	}
	(*S)->top=node;
}

char Pop(Stack **S){
	char data;
	if((*S)->top==NULL)
		data='?';
	else{		
		List *temp=(*S)->top;
		data=temp->data;
		if((*S)->top->next)
			(*S)->top=(*S)->top->next;
		else
			(*S)->top=NULL;
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
