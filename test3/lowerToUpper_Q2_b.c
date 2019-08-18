#include<stdio.h>
#include<stdlib.h>
#define SIZE 1024
void lowerToUpper(char *str);

int main(void){
	char *string=(char *)malloc(sizeof(char)*SIZE);
	printf("\nEnter your string: ");
	fgets(string,SIZE,stdin);
	printf("\nYour string: %s",string);
	lowerToUpper(string);
	printf("\nUpper Case: %s",string);
	printf("\n");
}

void lowerToUpper(char *str){
	int i=0;
	while(str[i]!='\0'){
		if(str[i]>=97 && str[i]<=122){
			str[i]=str[i]-32;
		}
		i+=1;
	}
}
