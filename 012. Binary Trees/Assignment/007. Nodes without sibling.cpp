void printNodesWithoutSibling(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root == NULL){
        return;
    }
    
    if(root->right == NULL && root->left!=NULL){
        cout<<root->left->data<<' ';
    }else if(root->left == NULL && root->right!=NULL){
        cout<<root->right->data<<' ';
    }
    
    printNodesWithoutSibling(root->left);
    printNodesWithoutSibling(root->right);
}