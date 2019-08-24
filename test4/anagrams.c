#include<stdio.h>
#include<stdlib.h>

#define SIZE 1024

typedef struct StructCharCount{
	int cnt,tot;
	char ch;
}CharCount;

int found(CharCount *record,char ch);
void getRecords(CharCount *records,char *str);
char *getLower(char *str);
void display(CharCount *records);
int isAnagrams(CharCount *r1,CharCount *r2);

int main(void){
	char *str1,*str2;
	str1=(char *)malloc(sizeof(char)*SIZE);
	str2=(char *)malloc(sizeof(char)*SIZE);
	
	printf("\nEnter your 1st string: ");
	fgets(str1,SIZE,stdin);
	
	printf("\nEnter your 2nd string: ");
	fgets(str2,SIZE,stdin);

	str1=getLower(str1);
	str2=getLower(str2);

	CharCount *records1=(CharCount *)malloc(sizeof(CharCount)*SIZE);
	CharCount *records2=(CharCount *)malloc(sizeof(CharCount)*SIZE);

	getRecords(records1,str1);
	getRecords(records2,str2);

	if(isAnagrams(records1,records2))
		printf("\nAnagram..!!");
	else
		printf("\nNot Anagram..!!");
	printf("\n\n");
	free(str1);
	free(str2);
	free(records1);
	free(records2);
}

int isAnagrams(CharCount *r1,CharCount *r2){
	if(r1->tot!=r2->tot)
		return 0;
	else{
		int flag;
		for(int i=0 ; i<r1->tot ; i++){
			flag=0;
			for(int j=0 ; j<r2->tot ; j++){
				if(r1[i].ch==r2[j].ch && r1[i].cnt==r2[j].cnt){
					flag=1;
				}
			}
			if(flag==0)
				return 0;
		}
		return 1;
	}
}

void getRecords(CharCount *records,char *str){
	int i=0,k;
	while(str[i]!='\0'){
		if(str[i]>=97 && str[i]<=122){
			k=found(records,str[i]);
			if(k!=-1)
				records[k].cnt+=1;
			else{
				records[records->tot].ch=str[i];
				records[records->tot].cnt+=1;		
				records->tot+=1;
			}
		}
		i+=1;
	}
}

int found(CharCount *records,char ch){
	for(int i=0 ; i<records->tot; i++){
		if(records[i].ch==ch)
			return i;
	}
	return -1;
}

char *getLower(char *str){
	int i=0;
	while(str[i]!='\0'){
		if(str[i]>=65 && str[i]<=91){
			str[i]=str[i]+32;
		}
		i+=1;
	}
	return str;
}

void display(CharCount *records){
	for(int i=0 ; i<records->tot ; i++){
		printf("\nch=%c count=%d",records[i].ch,records[i].cnt);
	}
}
