#define SWAP(X,Y,T) ((T)=(X),(X)=(Y),(Y)=(T))

void reverse(int *arr, int si, int ei){
    while(si<ei){
        int temp;
        SWAP(arr[si],arr[ei],temp);
        si++;
        ei--;
    }
}

void rotate(int *input, int d, int n)
{
    //Write your code here
	reverse(input,0,n-1);
    reverse(input,0,n-d-1);
    reverse(input,n-d,n-1);
}
