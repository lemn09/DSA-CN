#include<iostream>
#include<queue>
using namespace std;

template <typename T>
class BinaryTreeNode{
public:
    T data;
    BinaryTreeNode *right;
    BinaryTreeNode *left;

    BinaryTreeNode(T data){
        this->data= data;
        right= NULL;
        left=NULL;
    }

    ~BinaryTreeNode(){
        delete left;
        delete right;
    }
};

BinaryTreeNode<int>* takeInput(){
    int rootData;
    cout<<"Enter data: ";
    cin>>rootData;

    if(rootData == -1){             // Enter -1 to stop
        return NULL;
    }

    BinaryTreeNode<int> *root= new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int> *leftChild= takeInput();
    BinaryTreeNode<int> *rightChild= takeInput();
    root->left= leftChild;
    root->right= rightChild;

    return root;
}

BinaryTreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter root Data: ";
    cin>>rootData;
    if(rootData == -1){
        return NULL;
    }
    BinaryTreeNode<int> *root= new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        BinaryTreeNode<int> *front= pendingNodes.front();
        pendingNodes.pop();
        int childData;
        cout<<"Enter left Child Data of "<<front->data<<": ";
        cin>>childData;
        if(childData != -1){
            BinaryTreeNode<int> *leftChild= new BinaryTreeNode<int>(childData);
            front->left= leftChild;
            pendingNodes.push(leftChild);
        }

        cout<<"Enter right Child Data of "<<front->data<<": ";
        cin>>childData;
        if(childData != -1){
            BinaryTreeNode<int> *rightChild= new BinaryTreeNode<int>(childData);
            front->right= rightChild;
            pendingNodes.push(rightChild);
        }
        cout<<endl;
    }

    return root;
}

void printTree(BinaryTreeNode<int> *root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<": ";
    if(root->left){
        cout<<"L: "<<root->left->data<<' ';
    }
    if(root->right){
        cout<<"R: "<<root->right->data<<' ';
    }
    cout<<endl;
    printTree(root->left);
    printTree(root->right);
}

int numNodes(BinaryTreeNode<int> *root){
    if(root == NULL){
        return 0;
    }
    return 1 + numNodes(root->left) + numNodes(root->right);
}

void inorder(BinaryTreeNode<int> *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<' ';
    inorder(root->right);
}

//1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main(){
//    BinaryTreeNode<int> *root= new BinaryTreeNode<int>(10);
//    BinaryTreeNode<int> node1= new BinaryTreeNode<int>(20);
//    BinaryTreeNode<int> node2= new BinaryTreeNode<int>(30);
//    root->left= node1;
//    root->right= node2;

    BinaryTreeNode<int> *root= takeInputLevelWise();
    printTree(root);
    cout<<"\nTotal Nodes: "<<numNodes(root)<<endl;
    inorder(root);
    cout<<endl;
    delete root;
    return 0;
}
