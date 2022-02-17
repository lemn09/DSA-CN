bool isCousin(BinaryTreeNode<int> *root, int p, int q) {
   	if(root==NULL){
        return false;
    }
    queue<BinaryTreeNode<int>* > pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
	bool foundP=false, foundQ=false;
    while(!pendingNodes.empty()){
        BinaryTreeNode<int>* f = pendingNodes.front();
        if(f == NULL){
            if(foundP && foundQ){
                return true;
            } else if((foundP && !foundQ) || (foundQ && !foundP)){
                return false;
            }
            pendingNodes.pop();
            if(!pendingNodes.empty()){
                pendingNodes.push(NULL);
            }
        } else {
            pendingNodes.pop();
            if(f->data == p){
                foundP=true;
            } else if(f->data == q){
                foundQ=true;
            }
            if(f->left && f->right){
                if(f->left->data == p && f->right->data == q ){
                	return false;
                } else if(f->left->data == q && f->right->data == p){
                    return false;
                }
            }
            
            if(f->left != NULL){
                pendingNodes.push(f->left);
            }
            if(f->right != NULL){
                pendingNodes.push(f->right);
            }
        }
    }
	return false;
}