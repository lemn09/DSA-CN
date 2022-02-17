int requiredSum(BinaryTreeNode<int> *root, int sum, int data ){
    if(root == NULL){
        return 0;
    }
    
    
    int leftSum= requiredSum(root->left, sum, data);
    int rightSum= requiredSum(root->right, sum, data);
    if(root->data > data){
        sum+= data;
    }
    
    return sum + leftSum + rightSum;
}

BinaryTreeNode<int> *helper(BinaryTreeNode<int> *root){
    if(root == NULL){
        return NULL;
    }
    
	int data= requiredSum(root, 0, root->data);
    BinaryTreeNode<int> *newTree= new BinaryTreeNode<int>(data);
    newTree->left= helper(root->left);
    newTree->right= helper(root->right);
    
    return newTree;
}


void replaceWithLargerNodesSum(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root == NULL){
        return;
    }
    
    BinaryTreeNode<int> *extra= new BinaryTreeNode<int>(root->data);
   root= helper(root);
   