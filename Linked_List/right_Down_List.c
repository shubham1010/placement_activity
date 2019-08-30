#include<stdio.h>
#include<stdlib.h>

typedef struct StructRightDownList{
	int data;
	struct StructRightDownList *next,*down;
}RDList;
RDList *createList(int n);
RDList *isPresentNode(RDList *head,int data);
void insertDown(RDList **head);
void sort_two_list(RDList **head1,RDList **head2);
void make_Single_Sorted_List(RDList **head);
void display_RDList(RDList *head);
void display_RList(RDList *head);
void deleteRDList(RDList **head);

int main(void){
	RDList *head=NULL,*temp;
	int ch,n;
	while(1){
		printf("\n____________________________________________________");
		printf("\n1: Create Right List:\n2: To Insert Down Node\n3: Display\n4: Make Single Sorted List\n5: Exit");
		printf("\n____________________________________________________");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("\nEnter how many nodes in right list: ");
				scanf("%d",&n);
				head=createList(n);
				break;

			case 2:
				insertDown(&head);
				break;
			case 3:
				display_RDList(head);
				break;

			case 4:			
				make_Single_Sorted_List(&head);
				if(head)
					printf("\n***Right Down List is Sorted flatterned***");
				break;

			case 5:
				break;
		}
		if(ch==5)
			break;
		printf("\n\n");
	}
	deleteRDList(&head);
}



RDList *createList(int n){
	RDList *newNode,*head=NULL,*temp;
	for(int i=0 ; i<n ; i++){
		newNode=(RDList *)malloc(sizeof(RDList));
		printf("Enter data for %d node: ",i+1);
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

void insertDown(RDList **head){
	display_RList(*head);
	RDList *temp;
	int data;
	printf("\nNotice: You are allow to insert down to only above node(s)..!!!");
	printf("\nEnter node value to insert down: ");
	scanf("%d",&data);
	temp=isPresentNode(*head,data);
	if(temp){
		printf("\nEnter how many nodes to insert down: ");
		scanf("%d",&data);
		temp->down=createList(data);
	}
	else
		printf("\n\t***Node does not exist, Try another node***");
}

RDList *isPresentNode(RDList *head,int data){
	RDList *temp=head;
	while(temp!=NULL){
		if(temp->data==data)
			break;
		temp=temp->next;
	}
	return temp;
}
void display_RList(RDList *head){
	RDList *temp=head;
	while(temp!=NULL){
		printf("\t%d->\b\b",temp->data);
		temp=temp->next;
	}
	printf("  ");
}
void display_RDList(RDList *head){
	RDList *temp=head;
	while(temp!=NULL){
		printf("\t%d->\b\b",temp->data);
		if(temp->down)
			display_RDList(temp->down);
		temp=temp->next;
	}
	printf("  ");
}

void deleteRDList(RDList **head){
	RDList *temp=*head;
	while(*head!=NULL){
		if(temp->down)
			deleteRDList(&(temp->down));
		free(temp);
		*head=(*head)->next;
		temp=*head;
	}
}

void make_Single_Sorted_List(RDList **head){
	RDList *shead,*temp=*head;
	shead=temp->down;
	temp=temp->next;
	while(temp!=NULL){
		sort_two_list(&shead,&(temp->down));
		temp->down=NULL;
		temp=temp->next;
	}
	sort_two_list(&shead,&(*head));
	(*head)->down=NULL;
	*head=shead;
}

void sort_two_list(RDList **head1,RDList **head2){
	RDList *p1=*head1,*q1,*p2=*head2,*q2;
	RDList *shead=NULL,*cur;
	while(p1!=NULL && p2!=NULL){
		if(p1->data>p2->data){
			if(shead==NULL){
				shead=p2;
				cur=p2;
			}
			else{
				cur->next=p2;
				cur=cur->next;
			}
			//printf("%d ",p2->data);
			p2=p2->next;
		}
		else{
			if(shead==NULL){
				shead=p1;
				cur=p1;
			}
			else{
				cur->next=p1;
				cur=cur->next;
			}
			//printf("%d ",p1->data);
			p1=p1->next;
		}
	}
	
	while(p1!=NULL){
		//printf("%d ",p1->data);
		if(shead==NULL){
			shead=p1;
			cur=p1;
		}
		cur->next=p1;
		cur=cur->next;
		p1=p1->next;
	}
	
	while(p2!=NULL){
		//printf("%d ",p2->data);
		if(shead==NULL){
			shead=p1;
			cur=p1;
		}
		cur->next=p2;
		cur=cur->next;
		p2=p2->next;
	}
	*head1=shead;
}
