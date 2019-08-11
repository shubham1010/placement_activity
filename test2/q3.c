#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "queueLL.h"

typedef struct StructLRTF{
	char pname[10];
	float at,bt,bt1,totbt,ft,tat,wt;
}LRTF;

void acceptInput(LRTF *arr,int n);
Queue *LRTF_Compute(LRTF *arr,int n);
void compute_time(LRTF *arr, int n);
void displayQueue(Queue *Q);
void display(LRTF *arr,int n);
int get_Min_at_Index(LRTF *arr,int n,int findat);

int main(void){
	Queue *Q=NULL;
	LRTF *arr;
	int n;
	printf("\nEnter how many process: ");
	scanf("%d",&n);
	arr=(LRTF *)malloc(sizeof(LRTF)*n);
	acceptInput(arr,n);

	Q=LRTF_Compute(arr,n);
	//Gantt Chart
	displayQueue(Q);
	printf("\n\n");
	//computing waiting and turn around time
	compute_time(arr,n);
	display(arr,n);
	printf("\n\n");
	deleteQueue(&Q);
}

void acceptInput(LRTF *arr,int n){
	for(int i=0 ; i<n ; i++){
		printf("\nEnter the process name: ");
		scanf("%s",arr[i].pname);
		printf("\nEnter the arrival time of %s process: ",arr[i].pname);
		scanf("%f",&arr[i].at);
		printf("\nEnter the burst time of %s process: ",arr[i].pname);
		scanf("%f",&arr[i].bt);
		arr[i].bt1=arr[i].bt;
		arr->totbt+=arr[i].bt;
	}
}

Queue *LRTF_Compute(LRTF *arr,int n){
	Queue *Q=createQueue();
	List *node;
	int atmin;
	float totcur=0;
	while(arr->totbt!=0){
		atmin=get_Min_at_Index(arr,n,totcur);
		if(atmin==-1){
			node=(List *)malloc(sizeof(List));
			strcpy(node->pname,"-------IDEAL-------");
			node->st=totcur;
			totcur+=1;
			node->ft=totcur;
			EnQueue(Q,node);
			arr->totbt+=1;
		}
		else{
			if(Q->rear==NULL || strcmp(Q->rear->pname,arr[atmin].pname)!=0){
				node=(List *)malloc(sizeof(List));
				strcpy(node->pname,arr[atmin].pname);			
				node->st=totcur;
				totcur+=1;
				node->ft=totcur;
				arr[atmin].ft=node->ft;
				EnQueue(Q,node);
			}
			else{
				totcur+=1;
				Q->rear->ft=totcur;
				arr[atmin].ft=Q->rear->ft;
			}

		}
		arr->totbt-=1;
	}
	return Q;
}

int get_Min_at_Index(LRTF *arr,int n,int findat){
	int temp[n],j=0,flag=0;
	for(int i=0 ; i<n ; i++){

		if(arr[i].at<=findat && arr[i].bt>0){
			temp[j]=i;
			j+=1;
			flag=1;
		}
			
	}
	if(flag==1){
		int max=arr[temp[0]].bt;
		int k=temp[0];
		for(int i=1 ; i<j ; i++){
			if(arr[temp[i]].bt>max){
				max=arr[temp[i]].bt;
				k=temp[i];
			}
		}
		arr[k].bt-=1;
		return k;
	}
	else
		return -1;
}

void displayQueue(Queue *Q){
	printf("\n\t***Gantt chart***");
	while(Q->front!=NULL){
		printf("\npname=%s start=%f end=%f",Q->front->pname,Q->front->st,Q->front->ft);
		Q->front=Q->front->next;
	}
}

void compute_time(LRTF *arr, int n){
	for(int i=0 ; i<n ; i++){
		arr[i].tat=arr[i].ft-arr[i].at;
		arr[i].wt=arr[i].tat+arr[i].bt1;
	}
}

void display(LRTF *arr,int n){
	float avgwt=0,avgtat=0;
	for(int i=0 ; i<n ; i++){
		printf("\npname= %s waiting time=%f turn around time=%f",arr[i].pname,arr[i].wt,arr[i].tat);
		avgwt+=arr[i].wt;
		avgtat+=arr[i].tat;
	}

	printf("\n\n\t***Average Waiting Time= %f***",avgwt/n);
	printf("\n\t***Average Turn Around Time= %f***",avgtat/n);
}

