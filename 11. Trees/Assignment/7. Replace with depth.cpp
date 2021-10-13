void replaceWithDepthValue(TreeNode<int>* root,int d=0) {
    // Write your code here
    if(root == NULL){
        return;
    }


    root->data= d;
	for(int i=0; i<root->children.size(); i++){
        replaceWithDepthValue(root->children[i],d+1);
    }
}
