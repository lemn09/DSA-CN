int getSum(BinaryTreeNode<int>* root) {
    // Write your code here
    if(root == NULL){
        return 0;
    }
    return root->data + getSum(root->right) + getSum(root->left);
}