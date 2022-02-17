#include<climits>
int maximum(BinaryTreeNode<int>* root){
    if(root == NULL){
        return INT_MIN;
    }
    return max(root->data, max(maximum(root->left), maximum(root->right)));
}
int minimum(BinaryTreeNode<int>* root){
    if(root == NULL){
        return INT_MAX;
    }
    return min(root->data, min(minimum(root->left), minimum(root->right)));
}
bool isBST(BinaryTreeNode<int> *root) {
	if(root == NULL){
        return true;
    }
    int leftMax = maximum(root->left);
    int rightMin = minimum(root->right);

    bool ans = (root->data > leftMax) && (root->data <= rightMin) 
                    && isBST(root->left) && isBST(root->right);
    r