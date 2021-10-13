TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    // Write your code here
    if(root == NULL){
        return root;
    }

    TreeNode<int> *max= root;
    TreeNode<int> *temp;
    for(int i=0; i<root->children.size(); i++){
        temp= maxDataNode(root->children[i]);
        if(temp->data > max->data){
            max= temp;
        }
    }

    return max;
}
