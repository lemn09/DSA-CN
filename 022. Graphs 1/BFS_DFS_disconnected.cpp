//adjacency matrix

#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

void printBFS(int fv, vector<vector<int>> &edges, vector<bool> &visited){
    visited[fv]= true;
    queue<int> pendingVertices;
    pendingVertices.push(fv);
    while(!pendingVertices.empty()){
        int top= pendingVertices.front();
        pendingVertices.pop();
        
        cout<<top<<" ";
        for(int i=0; i<edges[top].size(); i++){
            if(i == top || visited[i] == true){
                continue;
            }else if(edges[top][i] == 1){
                pendingVertices.push(i);
                visited[i]= true;
            }
            
        }
    }
}

void printDFS(int fv, vector<vector<int>> &edges, vector<bool> &visited){
    cout<<fv<<" ";
    visited[fv]= true;
    for(int i=0; i<edges[fv].size(); i++){
        if(i == fv || visited[i] == true){
            continue;
        }else if(edges[fv][i] == 1){
            printDFS(i, edges, visited);
        }
    }
}

void BFS(int n, vector<vector<int>> &edges){
    vector<bool> visited(n, false);
    for(int i=0; i<n; i++){
        if(visited[i] == false){
            printBFS(i, edges, visited);
        }
    }
}

void DFS(int n, vector<vector<int>> &edges){
    vector<bool> visited(n, false);
    for(int i=0; i<n; i++){
        if(visited[i] == false){
            printDFS(i, edges, visited);
        }
    }
}

int main(){
    int n;

    cin>>n;
    int edg;

    cin>>edg;
    vector<vector<int>> edges(n, vector<int>(n,0));

    for(int i=0; i<edg; i++){
        int fv,sv;
        cin>>fv>>sv;
        edges[fv][sv]= 1;
        edges[sv][fv]= 1;
    }

    cout<<"DFS: ";
    DFS(n,edges);
    cout<<"\nBFS: ";
    BFS(n,edges);
}