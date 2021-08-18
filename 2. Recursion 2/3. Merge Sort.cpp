#include<iostream>
using namespace std;

void Merge(int *arr, int si, int ei)
{
    int len= ei-si+1;
    int mid= (si+ei)/2;
    int* narr= new int[len];
    int i=si,j=mid+1,pos=0;
    while(i<=mid && j<=ei)
    {
        if(arr[i] < arr[j])
            narr[pos++]= arr[i++];
        else
            narr[pos++]= arr[j++];
    }
    while(i<=mid)
        narr[pos++]= arr[i++];
    while(j<=ei)
        narr[pos++]= arr[j++];
    pos=0;
    for(int i=si; i<=ei; i++)
        arr[i]= narr[pos++];
    delete []narr;
}

void merge_sort(int *arr, int si, int ei)
{
    if(si >= ei)
        return;
    int mid= (si+ei)/2;
    merge_sort(arr, si, mid);
    merge_sort(arr,mid+1,ei);
    Merge(arr,si,ei);
}

int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int *arr= new int[n];
    cout<<"Enter "<<n<<" elements of the array: ";
    for(int i=0; i<n; i++)
        cin>>arr[i];
    merge_sort(arr,0,n-1);
    cout<<"\nSorted Array: ";
    for(int i=0; i<n; i++)
        cout<<arr[i]<<' ';
    cout<<endl;
    delete []arr;
}
