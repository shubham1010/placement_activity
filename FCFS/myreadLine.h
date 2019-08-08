#include<string.h>
typedef struct mySplitStructure{
	char *vname;
	int msi;
}mySplitStruct;
mySplitStruct mysplitObj[50];

char *myreadLine(char *line,FILE *fp){
    int i=0;
	char ch;
	while(ch!=EOF){	
		ch = fgetc(fp);				
		if(ch=='\n'){
			return line;					
		}
	
		line[i]=ch;	
		i++;
		line[i]='\0';
	}
					
	if(ch==EOF){
		strcpy(line,"EOF");
		return line;
	}
	
}

void mysplit(char line[],char ch){
	char found[100],line1[100];
	strcpy(line1,line);
	int i=0,j=0,index=0,flag=0,len;
	len=strlen(line1);
//	while(line1[index]!='\n'){
	while(index!=len){
		if(line1[index]==ch && flag==1){
			mysplitObj[j].vname=(char *)malloc(sizeof(char)*strlen(found));
			strcpy(mysplitObj[j].vname,found);
			j++;
			i=0;
		}
		if(line1[index]!=' ' && line1[index]!='\t' && line1[index]!=ch && line1[index]!='\n'){
			flag=1;
			found[i]=line1[index];
			i++;
			found[i]='\0';
		}
		index++;
	}
	mysplitObj[j].vname=(char *)malloc(sizeof(char)*strlen(found));
	strcpy(mysplitObj[j].vname,found);
	j++;
	mysplitObj->msi=j;
	j=0;
	index=0;
}

void displaySplit(void){
	printf("\nSplited strings : ");
	for(int i=0 ; i<mysplitObj->msi ; i++){
		printf("%s ",mysplitObj[i].vname);
	}
}
