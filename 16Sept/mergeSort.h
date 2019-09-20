void mergeSort(int *arr,int *temp,int l,int r);
void merge(int *arr,int *temp,int l,int m,int r);

void mergeSort(int *arr,int *temp,int l,int r){
	if(l<r){
		int m=(l+r)/2;
		mergeSort(arr,temp,l,m);
		mergeSort(arr,temp,m+1,r);
		merge(arr,temp,l,m+1,r);
	}
}

void merge(int *arr,int *temp,int l,int m,int r){
	int size=r-l+1,i=l,low_end=m-1;

	while(l<=low_end && m<=r){
		if(arr[l]>arr[m]){
			temp[i]=arr[m];
			m+=1;
			i+=1;
		}
		else{
			temp[i]=arr[l];
			l+=1;
			i+=1;
		}
	}

	while(l<=low_end){
		temp[i]=arr[l];
		i+=1;
		l+=1;
	}

	while(m<=r){
		temp[i]=arr[m];
		i+=1;
		m+=1;
	}

	for(i=0 ; i<=size ; i++){
		arr[r]=temp[r];
		r-=1;
	}
}

