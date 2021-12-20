#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

vector<int> removeDuplicates(int *arr, int n){
    vector<int> output;
    unordered_map<int, bool> seen;
    for(int i=0; i<n; i++){
        if(seen.count(arr[i]) > 0){
            continue;
        }
        seen[arr[i]]= true;
        output.push_back(arr[i]);
    }
    return output;
}

int main(){
    int arr[]= {1,2,2,3,5,2,3,4,6,4,6,8};
    vector<int> output= removeDuplicates(arr, sizeof(arr)/sizeof(int));
    for(int i=0; i<output.size(); i++){
        cout<<output.at(i)<<' ';
    }
    cout<<endl;
    return 0;
}