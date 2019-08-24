
/*Pass the filename as command line argument*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 1024

typedef struct StructNTimes{
	int totwords,n,totlines;
	char word[SIZE];
}AllWords;


AllWords *readFile(char *fname);
void display(AllWords *words);
char *reverse(char *string);

int main(int argc,char *argv[]){
	if(argc!=2){
		printf("\nPlease pass <executable> <filename> command line.\n\n");
		exit(1);
	}
	AllWords *words;
	words=readFile(argv[1]);

	int n;

	printf("\nEnter your n: ");
	scanf("%d",&n);
	words->n=n;	
	
	display(words); // for display output
	printf("\n\n");
}

AllWords *readFile(char *fname){
	FILE *fp=fopen(fname,"r");
	if(fp==NULL){
		printf("\nFile not found..!!");
		printf("\nTry different file name..!!\n\n");
		exit(1);
	}
	int i=0;
	char ch;
	ch=fgetc(fp);
	char *temp=(char *)malloc(sizeof(char)*SIZE);

	AllWords *words=(AllWords*)malloc(sizeof(AllWords)*SIZE);
	int j=0;
	while(ch!=EOF){
		//printf("%c",ch);
		if(ch!=' '){ //making word
			temp[i]=ch;
			i+=1;
			temp[i]='\0';
		}
		if(ch=='\n'){
			words->totlines+=1;
		}
		if(ch==' ' || ch=='\n'){
			strcpy(words[j].word,reverse(temp)); // store founded word into declared structure
			j+=1;
			temp[0]='\0';
			i=0;
		}
		ch=fgetc(fp);

	}
	words->totwords=j;
	fclose(fp);
	return words;
}

char *reverse(char *string){
	int l=strlen(string);
	char ch;
	for(int i=0,j=l-1 ; i<j ; i++,j--){
		ch=string[i];
		string[i]=string[j];
		string[j]=ch;
	}
	return string;
}


void display(AllWords *words){
	if(words->totlines>1){ // if there are more than one lines (\n)
		for(int k=0 ; k<(words->n) ; k++){
			for(int i=words->totwords-1 ; i>=0 ; i--){
			//	for(int j=0 ; j<words->n ; j++)
					printf("%s ",words[i].word);
			}
		}
	}
	else{

		// for a single line remove \n character of last word
		strcpy(words[words->totwords-1].word,reverse(words[words->totwords-1].word));

		words[words->totwords-1].word[strlen(words[words->totwords-1].word)-1]='\0';
		strcpy(words[words->totwords-1].word,reverse(words[words->totwords-1].word));

		for(int i=words->totwords-1 ; i>=0 ; i--){
			for(int j=0 ; j<words->n ; j++)
				printf("%s ",words[i].word);
		}

	}
}
