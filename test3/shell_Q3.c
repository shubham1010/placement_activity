#include<stdio.h>
#include<unistd.h>	//execlp()
#include<fcntl.h>	//O_RDONLY
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
void count(char *operation,char *fname);
void typeline(char *s, char *fn);
void list(char *operation,char *dirname);

int main(void){
	char command[80],t1[20],t2[20],t3[20],t4[20];
	int n,status;
	system("clear");
	while(1){
		printf("18116$ ");
		fflush(stdin);
		fgets(command,80,stdin);
		n = sscanf(command,"%s %s %s %s",t1,t2,t3,t4);
		switch(n){
			case 1:
				if(strcmp(t1,"exit")==0)
					exit(1);
				if(!fork()){
					execlp(t1,t1,NULL);
				}
				else
					waitpid(-1,&status,0);
				break;
			case 2:
				if(!fork()){
					execlp(t1,t1,t2,NULL);
				}
				else
					waitpid(-1,&status,0);
				break;
		case 3:
			if(strcmp(t1,"typeline")==0 || strcmp(t1,"Typeline")==0)
				typeline(t2,t3);
			else if(strcmp(t1,"count")==0 || strcmp(t1,"Count")==0)
				count(t2,t3);
			else if(strcmp(t1,"list")==0 || strcmp(t1,"List")==0)
				list(t2,t3);
			else{
				if(!fork()){
					execlp(t1,t1,t2,t3,NULL);
				}
				else
					waitpid(-1,&status,0);
			}
			break;
		case 4:
			if(!fork()){
				execlp(t1,t1,t2,t3,t4,NULL);
			}
			else
				waitpid(-1,&status,0);
			break;
		}
		printf("\n");
	}                                   
}

void count(char *operation,char *fname){
	int handle;
	int lc=0,wc=0,cc=0;
	char ch;
	if((handle=open(fname,O_RDONLY))==-1){
		printf("File %s not found\n",fname);
		return;
	}
	while(read(handle,&ch,1)!=0){
		if(ch==' '|| ch=='\n')
			wc++;
		else
			cc++;			
		if(ch=='\n')
			lc++;
	}
    close(handle);
	if(strcmp(operation,"CW")==0){
		printf("Number of Character(s): %d",cc);
		printf("\nNumber of Word(s): %d",wc);
	}
	else if(strcmp(operation,"WL")==0){
		printf("Number of Word(s): %d",wc);
		printf("\nNumber of Line(s): %d",lc);
	}
	else if(strcmp(operation,"CL")==0){
		printf("Number of Character(s): %d",cc);
		printf("\nNumber of Line(s): %d",lc);
	
	}
	else if(strcmp(operation,"CWL")==0){
		printf("Number of Character(s): %d",cc);
		printf("\nNumber of Word(s): %d",wc);
		printf("\nNumber of Line(s): %d",lc);
	
	}
	else{
		printf("Please choose valid option..!!");
		printf("\nOptions are: CW,WL,CL,CWL");
	}
}

void typeline(char *s, char *fname){
	int handle,i=0,cnt=0,n;
	char ch;
	if((handle=open(fname,O_RDONLY))==-1){
		printf("File %s not found\n",fname);
		return;
	}
	if(strcmp(s,"a")==0){
		while(read(handle,&ch,1)!=0)
			printf("%c",ch);
		close(handle);
		return;
	}
	n=atoi(s);
	if(n>0){
		while(read(handle,&ch,1)!=0){
			if(ch=='\n')
				i++;
			if(i==n)
				break;
			printf("%c",ch);
		}
		close(handle);
		return;
	}
	if(n<0){
		while(read(handle,&ch,1)!=0){
			if(ch=='\n')
				cnt++;
		}
		lseek(handle,0,SEEK_SET); //lseek moves the read/write pointer 
		while(read(handle,&ch,1)!=0){  //SEEK_SET go at perticular line ,The offset is set to offset bytes
			if(ch=='\n')
				i++;
			if(i==cnt+n)
				break;
		}
		while(read(handle,&ch,1)!=0)
			printf("%c",ch);
		close(handle);
	}
}

void list(char *operation,char *dirname){
	if(strcmp(operation,"F")==0)
		system("ls -p | grep -v /");
	else if(strcmp(operation,"N")==0)
		system("ls | wc -l");
	else if(strcmp(operation,"I")==0)
		system("ls -i | grep -v /");
	else
		printf("\nPlease choose the valid option..!!");
}
