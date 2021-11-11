#include<cmath>

int height(BinaryTreeNode<int> *root){
    if(root == NULL){
		return 0;
    }
    return 1 + max(height(root->right), height(root->left));
}

bool isBalanced(BinaryTreeNode<int> *root) {
	// Write your code here
    if(root == NULL){
        return true;
    }
    
    if( abs(height(root->left) - height(root->right)) <=1 ){
        bool left= isBalanced(root->left);
        bool right= isBalanced(root->right);
        return left && right;
    }else{
		return false;
    }
    
}