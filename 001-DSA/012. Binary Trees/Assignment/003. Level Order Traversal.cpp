void printLevelWise(BinaryTreeNode<int> *root) {
    // Write your code here
    
    if(root == NULL){
        return;
    }
    
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    while(!pendingNodes.empty()){
        BinaryTreeNode<int> *front= pendingNodes.front();
        pendingNodes.pop();
        
        if(front == NULL){
            cout<<'\n';
            if(!pendingNodes.empty()){
				pendingNodes.push(NULL);
            }
        }
        
        else{
            cout<<front->data<<' ';
            
            if(front->left){
                pendingNodes.push(front->left);
            }
            
            if(front->right){
                pendingNodes.push(front->right);
            }
            
        }
    }
}