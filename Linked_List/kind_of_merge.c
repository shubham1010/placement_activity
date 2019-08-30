#include<stdio.h>
#include<stdlib.h>

typedef struct StructList{
	int data;
	struct StructList *next;
}List;

List *createList(int n);
void display(List *head);
void kind_of_merge(List **head1,List **head2);
void deleteList(List **head);

int main(void){
	int n;
	List *head1=NULL,*head2=NULL;
	printf("\nEnter how many elements in 1st list: ");
	scanf("%d",&n);
	head1=createList(n);
	printf("\nEnter how many elements in 2nd list: ");
	scanf("%d",&n);
	head2=createList(n);

	printf("\n1st List:");
	display(head1);
	printf("\n2nd List:");
	display(head2);

	kind_of_merge(&head1,&head2);
	
	printf("\n\nAfter Kind of Merge: \n");
	printf("\n1st List:");
	display(head1);
	printf("\n2nd List:");
	display(head2);

	deleteList(&head1);
	deleteList(&head2);
	printf("\n\n");
}

void deleteList(List **head){
	List *temp=*head;
	while(*head!=NULL){
		free(temp);
		*head=(*head)->next;
		temp=*head;
	}
}
List *createList(int n){
	List *newNode,*temp,*head=NULL;
	for(int i=0 ; i<n ; i++){
		newNode=(List *)malloc(sizeof(List));
		printf("\nEnter data for %d node: ",i+1);
		scanf("%d",&newNode->data);
		newNode->next=NULL;

		if(head==NULL)
			head=newNode;
		else{
			temp=head;
			while(temp->next!=NULL)
				temp=temp->next;
			temp->next=newNode;
		}
	}
	return head;
}

void display(List *head){
	if(head==NULL){
		printf(" NULL");
		return;
	}
	while(head!=NULL){
		printf("\t%d->\b\b",head->data);
		head=head->next;
	}
	printf("  ");
}

void kind_of_merge(List **head1,List **head2){
	List *p1=*head1,*q1,*p2=*head2,*q2;
	List *temp,*fhead=NULL;
	while(p1!=NULL && p2!=NULL){
		q1=p1;
		p1=p1->next;
		q1->next=NULL;

		q2=p2;
		p2=p2->next;
		q2->next=NULL;

		
		q1->next=q2;
		if(fhead==NULL){
			fhead=q1;
		}
		else{
			temp=fhead;
			while(temp->next!=NULL)
				temp=temp->next;
			temp->next=q1;
		}
	}
	if(p1 && !p2){
		temp=fhead;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=p1;
	}
	*head1=fhead;
	*head2=p2;
}
