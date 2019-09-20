#include<stdio.h>
#include<stdlib.h>

int numTriangles(int min,int max);

int main(void){
	int min,max;
	printf("\nEnter the min and max value: ");
	scanf("%d %d",&min,&max);

	printf("\nTotal number of triangles: %d\n\n",numTriangles(min,max));
}

int numTriangles(int min,int max){
	int size=max-min+1;
	int *arr=(int *)malloc(sizeof(int)*size);

	for(int i=0 ; i<size ; i++){
		arr[i]=min;
		min+=1;
	}
	
	printf("\nArray: ");
	for(int i=0 ; i<size ; i++)
		printf("%d ",arr[i]);
	printf("\n");
	int s1=0,s2=s1+1,s3=s2+1,cnt=0;

	while(s1<size-2){

		if(s2==size-1){
			s1+=1;
			s2=s1+1;
			s3=s2+1;
		}
		if(s3==size){
			s2+=1;
			s3=s2+1;
		}
		if(arr[s1]+arr[s2]>arr[s3] && s3<size){
			printf("(%d,%d,%d) ",arr[s1],arr[s2],arr[s3]);
			cnt+=1;
		}


		s3+=1;
		
	}

	free(arr);
	return cnt;
}
