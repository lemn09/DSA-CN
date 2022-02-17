oid insertDuplicateNode(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root == NULL){
        return;
    }
    
    insertDuplicateNode(root->left);
    insertDuplicateNode(root->right);
    BinaryTreeNode<int> *duplicate= new BinaryTreeNode<int>(root->data);
    if(root->left){
    	BinaryTreeNode<int> *temp= root->left;
        duplicate->left= temp;
    }
    root->left= duplicate;
    
}