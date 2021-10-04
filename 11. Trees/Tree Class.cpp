#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template <typename T>
class TreeNode{

    public:
        T data;
        vector<TreeNode<T> *> children;

    TreeNode(T data){
        this->data= data;
    }

    ~TreeNode(){
        for(int i=0; i<children.size(); i++){
            delete children[i];
        }
    }
};



TreeNode<int>* takeInput(){             // returns address of root
    int rootData;
    cout<<"Enter the data: ";
    cin>>rootData;
    TreeNode<int> *root= new TreeNode<int>(rootData);

    int n;      // no. of children
    cout<<"Enter the  no. of children of "<<rootData<<": ";
    cin>>n;

    for(int i=0; i<n; i++){
        TreeNode<int> *child= takeInput();
        root->children.push_back(child);
    }

    return root;
}


void printTree(TreeNode<int> *root){

    if(root == NULL){                   // edge case not base case
        return;
    }
    cout<<root->data<<": ";
    for(int i=0; i<root->children.size(); i++){
        cout<<root->children[i]->data << ' ';
    }
    cout<<endl;

    for(int i=0; i< root->children.size(); i++){
        printTree(root->children[i]);
    }
}


TreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter root data: "<<endl;
    cin>>rootData;
    TreeNode<int> *root= new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        TreeNode<int> *front= pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cout<<"Enter no. of children of "<<front->data<<": ";
        cin>>numChild;
        for(int i=0; i<numChild; i++){
            int childData;
            cout<<"Enter child no.: "<<i+1<<" of "<<front->data<<": ";
            cin>>childData;
            TreeNode<int> *child= new TreeNode<int>(childData);
            pendingNodes.push(child);
            front->children.push_back(child);
        }
        cout<<endl;
    }
    return root;
}

int countNodes(TreeNode<int> *root){
    if(root == NULL){
        return 0;
    }
    int counter=1;
    for(int i=0; i<root->children.size(); i++){
        counter+= countNodes(root->children[i]);
    }
    return counter;
}

void printAtLevelK(TreeNode<int> *root, int k){
    if(root == NULL){
        return;
    }

    if(k == 0){
        cout<<root->data<<endl;
        return;
    }

    for(int i=0; i<root->children.size(); i++){
        printAtLevelK(root->children[i],k-1);
    }
}

void printLevelWise(TreeNode<int> *root){
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    cout<<"\nTree: "<<endl;
    while(!pendingNodes.empty()){
        TreeNode<int> *top= pendingNodes.front();
        pendingNodes.pop();

        cout<<top->data<<": ";
        for(int i=0; i<top->children.size(); i++){
            cout<<top->children[i]->data;
            if( i+1 < top->children.size()){
                cout<<',';
            }
            pendingNodes.push(top->children[i]);
        }
        cout<<endl;
    }
}

void preorder(TreeNode<int> *root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<' ';
    for(int i=0; i<root->children.size(); i++){
        preorder(root->children[i]);
    }
}

void postorder(TreeNode<int> *root){
    if(root == NULL){
        return;
    }

    if(root->children.size() == 0){
        cout<<root->data<<' ';
    }else{
        for(int i=0; i<root->children.size(); i++){
            postorder(root->children[i]);
        }
        cout<<root->data<<' ';
    }
}

void deleteTree(TreeNode<int> *root){
    if(root == NULL){
        return;
    }

    for(int i=0; i<root->children.size(); i++){
        deleteTree(root->children[i]);
    }
    delete root;
}
// Tree: 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0 2
int main(){
    /**
    TreeNode<int> *root= new TreeNode<int>(1);
    TreeNode<int> *node1= new TreeNode<int>(2);
    TreeNode<int> *node2= new TreeNode<int>(3);

    root->children.push_back(node1);
    root->children.push_back(node2);
    **/

    TreeNode<int>* root= NULL;
    root= takeInputLevelWise();

    cout<<"\nTree   :\n";
    printLevelWise(root);

    int k;
    cout<<"Enter value of k(level/depth) : ";
    cin>>k;
    printAtLevelK(root,k);
    cout<<"\nTree Size: "<<countNodes(root)<<endl;

    cout<<"\nPreorder: ";
    preorder(root);
    cout<<"\nPostOrder: ";
    postorder(root);
    return 0;
}
