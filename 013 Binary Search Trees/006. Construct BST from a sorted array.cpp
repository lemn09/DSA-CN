BinaryTreeNode<int> *helper(int *input, int si, int ei){
	if(si > ei){
        return NULL;
    }    
    
    int mid= (si + ei)/2;
    BinaryTreeNode<int> *root= new BinaryTreeNode<int>(input[mid]);
    BinaryTreeNode<int>* leftChild= helper(input, si, mid-1);
    BinaryTreeNode<int> *rightChild= helper(input, mid+1, ei);
    
    root->left= leftChild;
    root->right= rightChild;
    
    return root;
}

BinaryTreeNode<int>* constructTree(int *input, int n) {
	// Write your code here
    return helper(input, 0, n-1);
}