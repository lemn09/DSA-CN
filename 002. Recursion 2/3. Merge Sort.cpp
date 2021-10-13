// Merge Sort
#include<iostream>
using namespace std;

void _merge(int *arr, int si, int ei)   //it's purpose is to take an array split the array in 2 and then create a new array copy the content of old arrays in sorted way and then paste it in the original array's recieved indices
{
    int len= (ei-si+1);
    int mid= (si+ei)/2;
    int *out= new int[len];
    int pos=0,i=si,j=mid+1;
    while(i<= mid  && j<=ei)
    {
        if(arr[i] <= arr[j])
            out[pos++]= arr[i++];
        else
            out[pos++]= arr[j++];
    }
    while(i<= mid)
        out[pos++]= arr[i++];
    while(j<=ei)
        out[pos++]= arr[j++];
    pos=0;
    for(int i=si; i<=ei; i++)
        arr[i]= out[pos++];
    delete []out;
}

void mergesort(int *arr, int si, int ei)    //it's purpose is to split the array in half as long as it's possible
{
    if(si>=ei)  return;
    int mid= (si+ei)/2;
    mergesort(arr, si, mid);
    mergesort(arr, mid+1, ei);
    _merge(arr,si,ei);
}

int main()
{
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int *arr= new int[n];
    cout<<"\nEnter the elements of the array: ";
    for(int i=0; i<n; i++)
        cin>>arr[i];
    mergesort(arr,0,n-1);
    cout<<"\nSorted Array: ";
    for(int i=0; i<n; i++)
        cout<<arr[i]<<' ';
    cout<<endl;
    delete []arr;
    return 0;
}
