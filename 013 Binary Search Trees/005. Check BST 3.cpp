#include<iostream>
#include<climits>
using namespace std;

// top to bottom approach
bool IsBST3(BinaryTreeNode<int> *root, int min= INT_MIN, int max= INT_MAX){
    if(root == NULL){
        return true;
    }

    if(root->data < min || root->data > max){
        return false;
    }

    bool isLeftOk= IsBST3(root->left, min, root->data - 1);
    bool isRightOk= IsBST3(root->right, root->data, max);
    return isLeftOk && isRightOk;
}
