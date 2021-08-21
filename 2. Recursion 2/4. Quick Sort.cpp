//Quick sort
#include<iostream>
using namespace std;

#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

int _partition(int *arr, int si, int ei)
{
    int pivot= arr[si],countSmaller=0;
    for(int i=si+1; i<=ei; i++)
        if(arr[i] <= pivot)
            countSmaller++;
    int pivotIndex= countSmaller + si;
    int temp;
    SWAP(arr[si],arr[pivotIndex],temp);
    int i=si,j=ei;
    while(i<pivotIndex && j>pivotIndex)
    {
        if(arr[i] <= pivot)
            i++;
        else if(arr[j] > pivot)
            j--;
        else
        {
            SWAP(arr[i],arr[j],temp);
            i++;
            j--;
        }
    }
    return pivotIndex;
}

void qsort(int *arr, int si, int ei)
{
    if(si >= ei)
        return;
    int pos= _partition(arr,si,ei);
    qsort(arr, si, pos-1);
    qsort(arr,pos+1,ei);
}

int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int *arr= new int[n];
    cout<<"\nEnter "<<n<<" elements for the array: ";
    for(int i=0; i<n; i++)
        cin>>arr[i];
    qsort(arr,0,n-1);
    cout<<"\nSorted Array: ";
    for(int i=0; i<n; i++)
        cout<<arr[i]<<' ';
    cout<<endl;
    delete []arr;
    return 0;
}
