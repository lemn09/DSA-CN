bool isNodePresent(BinaryTreeNode<int> *root, int x) {
    // Write your code here
    if(root == NULL){
        return 0;
    }

    if(root->data == x){
        return 1;
    }
    return isNodePresent(root->left,x) || isNodePresent(root->right,x);
}
