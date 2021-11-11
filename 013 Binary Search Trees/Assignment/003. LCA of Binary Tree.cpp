nt getLCA(BinaryTreeNode <int>* root , int a, int b) {
    // Write your code here
    if(root == NULL){
        return -1;
    }
    
    if(root->data == a || root->data == b){
        return root->data;
    }
    
    int leftAns= getLCA(root->left, a, b);
    int rightAns= getLCA(root->right, a, b);
    
    if(leftAns == -1 && rightAns == -1){
        return NULL;
    }else if(leftAns == -1){
        return rightAns;
    }else if(rightAns == -1){
        return leftAns;
    }
    
    return root->data;
}