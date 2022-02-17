#include<climits>

pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
	// Write your code here
    if(root == NULL){
		pair<int, int> p;
        p.first=INT_MAX;
        p.second=INT_MIN;
        return p;
    }

    pair<int, int> leftAns= getMinAndMax(root->left);
    pair<int, int> rightAns= getMinAndMax(root->right);

    pair<int, int> p;
    p.first= min(root->data, min(leftAns.first, rightAns.first));
    p.second= max(root->data, max(leftAns.second, rightAns.second));

    return p;
}
