#include<stdio.h>
#include<stdlib.h>
#include "myreadLine.h"

typedef struct StructFCFS{
	char *pname;
	float bt,at,st,ft,wt,tat;
}FCFS;
void display(FCFS *allprocess,int n);
FCFS *acceptInput(int *n);
void sortByAT(FCFS *totProcess,int n);
void fcfs(FCFS *totProcess,int n);
void displayGantt(FCFS *totProcess,int n);
void allDetails(FCFS *totProcess,int n);

int main(void){
	FCFS *totProcess;
	int n;
	printf("\nEnter how many process(es): ");
	scanf("%d",&n);
	//totProcess=(FCFS *)malloc(sizeof(FCFS)*n);
	totProcess=acceptInput(&n);
	display(totProcess,n);
	printf("\n\n");
	fcfs(totProcess,n);
	printf("\n\n");
	displayGantt(totProcess,n);
	allDetails(totProcess,n);
	printf("\n\n");
}

void allDetails(FCFS *totProcess,int n){
	printf("\n\t\t***All Details about every process***\n");
	float avgwt=0,avgtat=0;
	for(int i=0 ; i<n ; i++){
		printf("\nProcess Name: %s",totProcess[i].pname);
		printf("\nArrival Time: %f",totProcess[i].at);
		printf("\nWaiting Time: %f",totProcess[i].wt);
		printf("\nTurn Around Time: %f",totProcess[i].tat);
		printf("\n");
		avgwt+=totProcess[i].wt;
		avgtat+=totProcess[i].tat;
	}
	printf("\n\t***Average Waiting Time= %f(ms)***",(avgwt/n));
	printf("\n\t***Average Turn Around Time= %f(ms)***",(avgtat/n));
}
void displayGantt(FCFS *totProcess,int n){
	printf("\n\t\t*** Gantt Chart ***");
	printf("\n--------------------------------------------------------------\n|");
	for(int i=0 ; i<n-1 ; i++){
		printf("\t%s\t|",totProcess[i].pname);
		if(totProcess[i].ft!=totProcess[i+1].st){
			printf("\t\t|");
		}
	}
	printf("\t%s\t|",totProcess[n-1].pname);
	printf("\n");
	for(int i=0 ; i<n ; i++){
		printf("%f\t",totProcess[i].st);
		if(totProcess[i].ft!=totProcess[i+1].st && i!=(n-1)){
			printf("%f",totProcess[i].ft);
			printf("|Ideal|\t");
		}
		
	}
	printf("%f",totProcess[n-1].ft);
	printf("\n--------------------------------------------------------------");
}

void fcfs(FCFS *totProcess,int n){
	sortByAT(totProcess,n);
	float tot=0;
	for(int i=0 ; i<n ; i++){
		totProcess[i].st=tot;
		if(totProcess[i].st<totProcess[i].at){
			totProcess[i].st=totProcess[i].at;
			tot=totProcess[i].at;
		}
		tot+=totProcess[i].bt;
		totProcess[i].ft=tot;

		totProcess[i].wt=totProcess[i].st-totProcess[i].at;
		totProcess[i].tat=totProcess[i].ft-totProcess[i].at;
	}

	
}

void sortByAT(FCFS *totProcess,int n){
	//Bubble Sort
	float temp;
	char tname[10];
	for(int i=0 ; i<n ; i++){
		for(int j=i ; j<n ; j++){
			if(totProcess[i].at>totProcess[j].at){

				temp=totProcess[i].at;
				totProcess[i].at=totProcess[j].at;
				totProcess[j].at=temp;

				strcpy(tname,totProcess[i].pname);
				strcpy(totProcess[i].pname,totProcess[j].pname);
				strcpy(totProcess[j].pname,tname);

				temp=totProcess[i].bt;
				totProcess[i].bt=totProcess[j].bt;
				totProcess[j].bt=temp;
			}
		}
	}
}

FCFS *acceptInput(int *n){
	FCFS *totpro=(FCFS *)malloc(sizeof(FCFS)*(*n));
	if (!totpro){
		printf("\nMemory is not allocated.!!");
		exit(0);
	}
	
	FILE *fp=fopen("input.txt","r");
	if(fp==NULL){
		printf("\n***File Error: File Not Found..!!**");
		exit(1);
	}
	char *line=(char *)malloc(sizeof(char)*100);
	int ch=0;
	if (!line){
		printf("\nMemory is not allocated for line.!!");
		exit(1);
	
	}
	int i=0;
	myreadLine(line,fp);
	while(strcmp(line,"EOF")!=0){
		mysplit(line,' '); 
		if(mysplitObj->msi==3){
			// maximum name length of process
			if(ch<*n){
				totpro[i].pname=(char *)malloc(sizeof(char)*10);
				strcpy(totpro[i].pname,mysplitObj[0].vname);
				totpro[i].bt=atof(mysplitObj[1].vname);
				totpro[i].at=atof(mysplitObj[2].vname);
				i+=1;
			}
			else{
				printf("\nWarning: Too many processes are found in an input file...!!");
				printf("\n***Please specify the correct number of processes***\n");
				printf("\nYou are allow enter number greater than the total processes but not less than total processes.\n\n");
				exit(1);
			}
			ch+=1;
		}
		myreadLine(line,fp);
	}
	*n=ch;
	fclose(fp);
	free(line);
	return totpro;
}

void display(FCFS *allprocess,int n){
	printf("\n-----------------------------------------------------");
	printf("\nProcess\t\tBurst Time\t\tArrival Time");
	printf("\n-----------------------------------------------------");
	for(int i=0 ;i<n ; i++){
		printf("\n%s\t\t%f\t\t%f",allprocess[i].pname,allprocess[i].bt,allprocess[i].at);
	}
}
