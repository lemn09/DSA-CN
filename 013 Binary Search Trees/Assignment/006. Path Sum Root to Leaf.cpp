void helper(BinaryTreeNode<int> *root, int k, string output){
    if(root == NULL){
        
        //cout<<output<<"\tk: "<<k<<endl;
        return;
    }
    
    if(root->left == NULL && root->right == NULL){
        if(k == root->data){
            output+= to_string(root->data);
            cout<<output<<endl;
        }
        return;
    }
    
    output+= to_string(root->data);
    output+= ' ';
    
    helper(root->left, k - root->data, output);
    helper(root->right, k - root->data, output); 
}
void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) {
    // Write your code here
    helper(root,k, "");
       
}