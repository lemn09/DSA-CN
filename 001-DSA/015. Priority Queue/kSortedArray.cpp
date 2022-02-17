#include<iostream>
#include<queue>
using namespace std;

void kSortedArray(int *arr, int n, int k){
    priority_queue<int> pq;
    for(int i=0; i<k; i++){
        pq.push(arr[i]);
    }

    int currIndex= 0;
    for(int i=k; i<n; i++){
        arr[currIndex++]= pq.top();
        pq.pop();
        pq.push(arr[i]);
    }

    while(!pq.empty()){
        arr[currIndex++]= pq.top();
        pq.pop();
    }
}

void print(int *arr, int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}

int main(){
    int arr[]= {10,12,6,7,9};
    kSortedArray(arr, sizeof(arr)/ sizeof(int), 3);
    print(arr, sizeof(arr)/sizeof(int));
    cout<<endl;
    return 0;
}