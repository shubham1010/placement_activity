#include<stdio.h>
#include<stdlib.h>

typedef struct StructDLL{
	int data;
	struct StructDLL *prev,*next;
}DLL;

DLL *createDLL(int n);
void display(DLL *head);
void addOneToList(DLL **head);
void deleteList(DLL **head);

int main(void){
	int ch,n;
	DLL *head=NULL;
	while(1){
		printf("\n1: Enter Number\n2: Add 1 to list\n3: Display\n4: Exit");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("\nEnter your number: ");
				scanf("%d",&n);
				if(!head)
					head=createDLL(n);
				else{
					deleteList(&head);
					head=createDLL(n);
				}
				if(head)
					printf("\n\t\t***List is successfully created..!!***");
				break;

			case 2:
				if(!head){
					printf("\nNothing to add..!!");
					break;
				}
				addOneToList(&head);
				if(head->data>9){
					head->data=0;
					DLL *newNode=(DLL *)malloc(sizeof(DLL));
					newNode->data=1;
					newNode->prev=NULL;
					newNode->next=head;
					head=newNode;
				}	
				break;

			case 3:
				display(head);
				break;
			case 4:
				break;
			default:
				printf("\n\t**Please select the valid option..!!**");
		}
		if(ch==4)
			break;
	}
	deleteList(&head);
	if(!head)
		printf("\n\t\t***List is successfully deleted..!!***");
	printf("\n\n");
}

void deleteList(DLL **head){
	DLL *temp=*head;
	while(*head!=NULL){
		free(temp);
		*head=(*head)->next;
		temp=*head;
	}
}

DLL *createDLL(int n){
	DLL *newNode=NULL,*head=NULL;
	int r;
	while(n>0){
		r=n%10;
		newNode=(DLL *)malloc(sizeof(DLL));
		newNode->data=r;
		newNode->prev=NULL;
		newNode->next=NULL;

		if(head==NULL)
			head=newNode;
		else{
			newNode->next=head;
			head->prev=newNode;
			head=newNode;
		}
		n=n/10;
	}
	return head;
}

void display(DLL *head){
	while(head!=NULL){
		printf("\t%d->\b\b",head->data);
		head=head->next;
	}
	printf("  \n\n");
}

void addOneToList(DLL **head){
	DLL *temp=*head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->data+=1;
	while(temp!=*head && temp!=NULL){
		if(temp->data>9 && temp!=*head){
			temp->data=0;
			temp->prev->data+=1;
		}
		temp=temp->prev;
	}
}
