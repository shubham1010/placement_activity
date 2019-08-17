void displayArray(int *arr,int n);
void mergeSort(long int *arr,long int *temp,int l,int r);
void merge(long int *arr,long int *temp,int l,int mid,int r);

/*
int main(void){
	int *arr,*temp,n;
	printf("\nEnter how many elements: ");
	scanf("%d",&n);
	arr=(int *)malloc(sizeof(int)*n);
	printf("\nEnter %d numbers..!! ",n);
	for(int i=0 ; i<n ; i++)
		scanf("%d",&arr[i]);
	printf("\nOriginal Array: ");
	displayArray(arr,n);
	temp=(int *)malloc(sizeof(int)*n);
	mergeSort(arr,temp,0,n-1);
	printf("\nAfter sorting Array: ");
	displayArray(arr,n);
	printf("\n\n");
	free(arr);
	free(temp);
}

void displayArray(int *arr,int n){
	for(int i=0 ; i<n ; i++)
		printf("%d ",arr[i]);
}
*/
void mergeSort(long int *arr,long int *temp,int l,int r){
	int m;
	if(r>l){
		m=(l+r)/2;
		mergeSort(arr,temp,l,m);
		mergeSort(arr,temp,m+1,r);
		merge(arr,temp,l,m+1,r);
	}
}

void merge(long int *arr,long int *temp,int l,int m,int r){
	int temp_pos,left_end,size,i;
	temp_pos=l;
	size=r-l+1;
	left_end=m-1;
	while((l<=left_end) && (m<=r)){
		if(arr[l]<arr[m]){
			temp[temp_pos]=arr[l];
			temp_pos+=1;
			l+=1;
		}
		else{
			temp[temp_pos]=arr[m];
			temp_pos+=1;
			m+=1;
		}
	}
	while(l<=left_end){
		temp[temp_pos]=arr[l];
		temp_pos+=1;
		l+=1;
	}
	while(m<=r){
		temp[temp_pos]=arr[m];
		temp_pos+=1;
		m+=1;
	}
	for(i=0 ; i<=size ; i++){
		arr[r]=temp[r];
		r-=1;
	}
}
