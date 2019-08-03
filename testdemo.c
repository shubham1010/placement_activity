#include<stdio.h>
#include<stdlib.h>

void reverseString(char str[]);
int main(void){
	char str[100];
	printf("\nEnter your string: ");
	fgets(str,100,stdin);
	printf("\nYour String: %s",str);
	reverseString(str);
	printf("\n\n");
}


void reverseString(char str[]){
	int i=0,j=0,ni=0;
	char newStr[100],ch,temp[100];
	while(str[i]!='\0'){
		ch = str[i];
		if(ch!=' ' && ch!=',' && ch!='.' && ch!='"'){
			temp[j]=ch;
			j++;
			temp[j]='\0';
		}
		if(ch==' ' || ch==',' || ch=='.' && j!=0 || ch=='\0'){
			for(int k=j-1 ; k>=0 ; k--){
				newStr[ni]=temp[k];
				ni++;
			}
			newStr[ni]='\0';
			
			j=0;
		}
		if(ch==' ' || ch==',' || ch=='.' || ch=='"'){
			newStr[ni]=ch;
			ni++;
			newStr[ni]='\0';
		}
		i++;
	}

	newStr[ni]='\0';
	printf("\nNew String=%s",newStr);
}
