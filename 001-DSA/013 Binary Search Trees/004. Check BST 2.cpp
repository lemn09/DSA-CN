#include<iostream>
#include<climit>
using namespace std;

class IsBSTReturn{
public:
    bool isBST;
    int minimum;
    int maximum;
};

IsBSTReturn isBST2(BinaryTreeNode<int> *root){
    if(root==NULL){
        IsBSTReturn output;
        output.maximum= INT_MAX;
        output.minimum= INT_MIN;
        output.isBST= true;
    }

    IsBSTReturn leftChild= isBST2(root->left);
    IsBSTReturn rightChild= isBST2(root->right);

    int minimum= min(root->data, min(leftChild.minimum, rightChild.minimum));
    int maximum= max(root->data, max(leftChild.maximum, rightChild.maximum));
    bool isBST= (root->data > leftChild.maximum) && (root->data <= rightChild.minimum) && leftChild.isBST && rightChild.isBST;
    IsBSTReturn output;
    output.isBST= isBst;
    output.minimum= minimum;
    output.maximum= maximum;
    return output;
}
