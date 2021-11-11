BinaryTreeNode<int>* removeLeafNodes(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root == NULL){
        return NULL;
    }
    
    if(root->left == NULL && root->right == NULL){
        return NULL;
    }
    
    if(root->left){
        root->left= removeLeafNodes(root->left);
    }
    if(root->right){
        root->right= removeLeafNodes(root->right);
    }
    
    return root;
}