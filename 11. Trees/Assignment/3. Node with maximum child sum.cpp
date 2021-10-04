int childSum(TreeNode<int> *root){
    if(root == NULL){
        return 0;
    }
    int sum=root->data;
    for(int i=0; i<root->children.size(); i++){
        sum+= root->children[i]->data;
    }
    return sum;
}

TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    // Write your code here
    if(root == NULL){
        return root;
    }

    int maxSum=childSum(root);
	TreeNode<int>* ans=root;

    for(int i=0; i<root->children.size(); i++){
        TreeNode<int> *temp= maxSumNode(root->children[i]);
        int tempSum= childSum(temp);
        if( tempSum > maxSum){
			maxSum= tempSum;
            ans= temp;
        }
    }
    return ans;
}
