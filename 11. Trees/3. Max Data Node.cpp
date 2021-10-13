int getHeight(TreeNode<int>* root) {
    // Write your code here
    if(root == NULL){
        return 0;
    }

    int height= 1;
    for(int i=0; i<root->children.size(); i++){
        int temp= getHeight(root->children[i]);
        if(temp + 1 > height){
            height= temp + 1;
        }
    }
    return height;
}
