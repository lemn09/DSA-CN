#include <iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int returnMinV(vector<int> &weight, vector<bool> &visited){
    int minV= -1;
    for(int i=0; i<weight.size(); i++){
        if(visited[i] == false && (minV == -1 || weight[i] < weight[minV])){
            minV= i;
        }
    }
    
    return minV;
}

void solution(vector<vector<int>> &edges){
    int n= edges.size();
    vector<bool> visited(n, false);
    vector<int> weight(n, INT_MAX);
    vector<int> parent(n);
    parent[0]= -1;
    weight[0]= 0;

    
    for(int i=0; i<n; i++){
        int minV= returnMinV(weight, visited);
        visited[minV]= true;
        for(int j=0; j<n; j++){
            if( visited[j] == false && edges[minV][j] !=0 ){
                int wt= edges[minV][j];
                if( wt < weight[j]){
                    weight[j]= wt;
                    parent[j]= minV;
                }
            }
        }
        
    }
    
    for(int i=1; i<n; i++){
        if( parent[i] < i){
            cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
        }else{
            cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
        }
    }
}

int main(){
    int v,e;
    cin>>v>>e;
    vector<vector<int>> edges(v, vector<int>(v,0));
    for(int i=0; i<e; i++){
        int fv, sv, wt;
        cin>>fv>>sv>>wt;
        edges[fv][sv]= wt;
        edges[sv][fv]= wt;
    }
    cout<<endl;
    solution(edges);
}