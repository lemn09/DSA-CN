void merge(int *arr, int si, int ei){
	int mid= (si+ei)/2;
    int len= (ei-si+1);
    int *out= new int[len];
    int i=si,j=mid+1,pos=0;
    while(i<=mid && j<=ei){
        if(arr[i] < arr[j]){
            out[pos++]=arr[i++];
        }else{
            out[pos++]= arr[j++];
        }
    }
    while(i<=mid){
        out[pos++]= arr[i++];
    }
    while(j<=ei){
        out[pos++]= arr[j++];
    }

    pos=0;
    for(int i=si; i<=ei; i++){
        arr[i]= out[pos++];
    }
    delete []out;
}

void ms(int *arr, int si, int ei){
	if(si>=ei){
        return;
    }
    int mid= (si+ei)/2;
    ms(arr,si, mid);
    ms(arr,mid+1,ei);
    merge(arr,si,ei);
}

void intersection(int *arr1, int *arr2, int n, int m)
{
    //Write your code here
	ms(arr1,0,n-1);
    ms(arr2,0,m-1);
	int i=0,j=0;
    while(i<n && j<m){
        if(arr1[i] == arr2[j]){
            cout<<arr1[i]<<' ';
        	i++;
            j++;
        }else if(arr1[i] > arr2[j]){
            j++;
        }else{
            i++;
        }
    }
}
