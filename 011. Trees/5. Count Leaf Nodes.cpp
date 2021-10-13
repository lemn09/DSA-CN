int getLeafNodeCount(TreeNode<int>* root) {
    // Write your code here
    if(root == NULL){
        return 0;
    }
    if(root->children.size() == 0){
		return 1;
    }

    int count=0;
    for(int i=0; i<root->children.size(); i++){
        int smallCount= getLeafNodeCount(root->children[i]);
        count+=smallCount;
    }
    return count;
}
