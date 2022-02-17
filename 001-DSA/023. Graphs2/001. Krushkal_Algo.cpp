#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

class edge{
    public:
    	int v1;
    	int v2;
    	int weight;
};

// comparator function to sort object of class edge using stl
bool compare(edge const &a, edge const &b){
    return (a.weight < b.weight);
}

// return the top parent of a vertice
int findParent(int v, vector<int> &parent){
    if( v == parent[v]){
        return v;
    }
    return findParent(parent[v], parent);
}

// print output
void print(vector<edge> &list){
    for(int i=0; i<list.size(); i++){
        cout<<list[i].v1<<" "<<list[i].v2<<" "<<list[i].weight<<endl;
    }
}

// kruskal's algo
void getMST(int v, vector<edge> &input, vector<edge> &output){
    vector<int> parent(v);
    // initalizing parent array
    for(int i=0; i<v; i++){
        parent[i]= i;
    }
    // sorting input w.r.t. weight of an edge
    sort(input.begin(), input.end(), compare);
    // count to maintain the output size && idx to traverse input
    int count=0, idx=0;
    while(count < v-1 && idx < input.size()){
        edge currVertex= input[idx];
        int v1= currVertex.v1;
        int v2= currVertex.v2;

        // determination of parent of both the vertices of an edge
        int parV1= findParent(v1, parent);
        int parV2= findParent(v2, parent);

        // if uncommon parents then we can add the edge to mst, update the parent of either vertex and update count
        if( parV1 != parV2){
            parent[parV1]= parV2;
            output.push_back(input[idx]);
            ++count;
        }
        // update index for input list traversal
        idx++;
    }
}

int main() {
    // Write your code here
    int v,e;
    cin>>v>>e;
    vector<edge> input(e);
    for(int i=0; i<e; i++){
        int v1, v2, w;
        cin>>v1>>v2>>w;
        input[i].v1= v1;
        input[i].v2= v2;
        input[i].weight= w;
    }
    vector<edge> output;
    getMST(v, input, output);
    print(output);
    return 0;
}