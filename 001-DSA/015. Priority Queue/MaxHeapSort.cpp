#include<iostream>
#include<vector>

using namespace std;

#define SWAP(a,b,c)  ((c)= (a), (a)= (b), (b)= (c))

void print(int *arr, int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}

void heapSort(int *arr, int size){
    int temp;

    //heap arrangement
    for(int i=0; i<size; i++){
        int childIndex= i;
        while(childIndex > 0){
            int parentIndex= (childIndex - 1)/2;
            if(arr[parentIndex] < arr[childIndex]){
                SWAP(arr[parentIndex], arr[childIndex], temp);
                childIndex= parentIndex;
            }else{
                break;
            }
        }
    }
    //check
    //print(arr, size);

    //sorting(removeMax)
    int lastIndex= size - 1;
    while(lastIndex > 0){
        SWAP(arr[0], arr[lastIndex], temp);
        lastIndex--;

        int parentIndex= 0;
        int maxIndex;
        while(parentIndex < lastIndex){
            maxIndex= parentIndex;
            int leftChildIndex= 2*parentIndex + 1;
            int rightChildIndex= 2*parentIndex + 2;
            if(leftChildIndex <= lastIndex && arr[maxIndex] < arr[leftChildIndex]){
                maxIndex= leftChildIndex;
            }
            if(rightChildIndex <= lastIndex && arr[maxIndex] < arr[rightChildIndex]){
                maxIndex= rightChildIndex;
            }
            if(maxIndex == parentIndex){
                break;
            }else{
                SWAP(arr[maxIndex], arr[parentIndex], temp);
                parentIndex= maxIndex;
            }
        }
    }
}

int main(){
    int arr[]= {15, 40, 12,7,10,11,14,2};
    heapSort(arr, sizeof(arr)/sizeof(int));
    print(arr, sizeof(arr)/sizeof(int));
    return 0;
}