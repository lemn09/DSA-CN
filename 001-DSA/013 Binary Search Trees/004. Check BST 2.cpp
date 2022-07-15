#include<bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode *right;
    BinaryTreeNode *left;

    BinaryTreeNode(T data) {
        this->data = data;
        right = NULL;
        left = NULL;
    }

    ~BinaryTreeNode() {
        delete left;
        delete right;
    }
};

class IsBSTReturn {
public:
    bool isBST;
    int minimum;
    int maximum;
};

IsBSTReturn isBST2(BinaryTreeNode<int> *root) {
    if (root == NULL) {
        IsBSTReturn output;
        output.maximum = INT_MIN;
        output.minimum = INT_MAX;
        output.isBST = true;
        return output;
    }

    IsBSTReturn leftChild = isBST2(root->left);
    IsBSTReturn rightChild = isBST2(root->right);

    int minimum = min(root->data, min(leftChild.minimum, rightChild.minimum));
    int maximum = max(root->data, max(leftChild.maximum, rightChild.maximum));
    bool isBST = (root->data > leftChild.maximum) && (root->data <= rightChild.minimum) && leftChild.isBST && rightChild.isBST;
    IsBSTReturn output;
    output.isBST = isBST;
    output.minimum = minimum;
    output.maximum = maximum;
    return output;
}

BinaryTreeNode<int> *takeInputDFS() {
    int data;
    cin >> data;
    if (data == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(data);
    newNode->left = takeInputDFS();
    newNode->right = takeInputDFS();
    return newNode;
}

void print(BinaryTreeNode<int> *node) {
    if (node == NULL) {
        return;
    }

    cout << node->data << ':';
    if (node->left) {
        cout << "L:" << node->left->data << ',';
    }

    if (node->right) {
        cout << "R:" << node->right->data;
    }
    cout << endl;

    print(node->left);
    print(node->right);
}

int32_t main() {
    BinaryTreeNode<int> *root;
    root = takeInputDFS();
    cout << "Tree: ";
    print(root);
    cout << "Is BST: " << isBST2(root).isBST << endl;
}