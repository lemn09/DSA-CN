//adjacency matrix

#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

void bfs(int fv, vector<vector<int>> &edges, vector<bool> &visited){
    cout<<"BFS: ";
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

void dfs(int fv, vector<vector<int>> &edges, vector<bool> &visited){
    cout<<fv<<endl;
    visited[fv]= true;
    for(int i=0; i<edges[fv].size(); i++){
        if(i == fv || visited[i] == true){
            continue;
        }else if(edges[fv][i] == 1){
            dfs(i, edges, visited);
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

    vector<bool> visited(n,false);
  //  dfs(0,edges,visited);
    bfs(0,edges,visited);
}