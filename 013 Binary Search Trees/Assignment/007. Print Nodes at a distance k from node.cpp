void printNodesAtDepthK(BinaryTreeNode<int> *root, int k){
    if(root == NULL){
        return;
    }
    
    if(k == 0){
        cout<<root->data<<endl;
    }
    
    string output+= 48 + root->data;
    printNodesAtDepthK(root->left, k - root->data);
    printNodesAtDepthK(root->right, k - root->data);
}


void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
    // Write your code here
    helper(root, node)
}