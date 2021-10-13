bool isPresent(TreeNode<int>* root, int x) {
    // Write your code here
	if(root == NULL){
        return 0;
    }

    if(root->data == x){
        return 1;
    }

    bool ans=false;
    for(int i=0; i<root->children.size(); i++){
        ans= isPresent(root->children[i],x);
        if(ans){
            return ans;
        }
    }
    return ans;
}
