bool areIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {
    // Write your code here
    if(root1== NULL && root2==NULL){
        return true;
	}else if(root1==NULL || root2==NULL){
        return false;
    }

    if(root1->data == root2->data && root1->children.size() == root2->children.size()){
        for(int i=0; i<root1->children.size(); i++){
            return areIdentical(root1->children[i],root2->children[i]);
        }
        return true;
    }else{
        return false;
    }
}
