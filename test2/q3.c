#include<stdio.h>
#include<stdlib.h>

typedef struct StructLRTF{
	char pname[10];
	float at,bt,totbt;
	
}LRTF;
void acceptInput(LRTF *arr,int n);
void display(LRTF *arr,int n);
LRTF LRTF_Compute(LRTF *arr,int n);
int get_Min_at_Index(LRTF *arr,int n,int findat);

typedef struct StructList{
	char pname[10];
	float st,ft;
	struct StructList *next;
}List;

typedef struct StructQueue{
	List *front,*rear;
}Queue;

int main(void){
	LRTF *arr;
	int n;
	printf("\nEnter how many process: ");
	scanf("%d",&n);
	arr=(LRTF *)malloc(sizeof(LRTF)*n);
	acceptInput(arr,n);
	//display(arr,n);

	LRTF_Compute(arr,n);

	printf("\n\n");
}

void acceptInput(LRTF *arr,int n){
	for(int i=0 ; i<n ; i++){
		printf("\nEnter the process name: ");
		scanf("%s",arr[i].pname);
		printf("\nEnter the arrival time of %s process: ",arr[i].pname);
		scanf("%f",&arr[i].at);
		printf("\nEnter the burst time of %s process: ",arr[i].pname);
		scanf("%f",&arr[i].bt);
		arr->totbt+=arr[i].bt;
	}
}

void display(LRTF *arr,int n){
	for(int i=0 ; i<n ; i++){
		printf("\nProcess Name: %s Arrival Time= %f Burst Time= %f",arr[i].pname,arr[i].at,arr[i].bt);
	}
	printf("\nTotal Burst Time: %f",arr->totbt);
}

Queue *createQueue(void){
	Queue *Q=(Queue *)malloc(sizeof(Queue));
	Q->front=Q->rear=NULL;
	return Q;
}

LRTF LRTF_Compute(LRTF *arr,int n){
	//Queue *Q=createQueue();
	//List *node;
	int atmin;
	float totcur=0;
	while(arr->totbt!=0){
		atmin=get_Min_at_Index(arr,n,totcur);
		if(atmin==-1){
			totcur+=1;
			arr->totbt+=1;
		}
		else{
			/*node=(List *)malloc(sizeof(List));
			node->st=totcur;
			node->pname=arr[atmin_i].pname;
			node->ft = totcur;
	
			EnQueue(Q,node);
			*/
			printf("\npname=%s start time=%f",arr[atmin].pname,totcur);
			totcur+=1;
			printf(" end time=%f",totcur);
		}
		arr->totbt-=1;
	}
}

int get_Min_at_Index(LRTF *arr,int n,int findat){
	int temp[n],j=0,flag=0;
	for(int i=0 ; i<n ; i++){

		// work on this condition only
		//if condition is get well your job is done.
		//if((arr[i].at<=findat && findat<arr[i].bt) || (arr[i].at<=findat && arr[i].bt>=findat)){
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
