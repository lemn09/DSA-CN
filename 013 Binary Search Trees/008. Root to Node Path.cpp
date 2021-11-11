#include<vector>
vector<int>* getRootToNodePath(BinaryTreeNode<int> *root, int data){
    if(root == NULL){
        return NULL;
    }

    if(root->data == data){
        vector<int>* output= new vector<int>();
        output->push_back(root->data);
        return output;
    }

    vector<int> *leftOutput= getRootToNodePath(root->left, data);
    if(leftOutput != NULL){
        leftOutput->push_back(root->data);
        return leftOutput;
    }

    vector<int> *rightOutput= getRootToNodePath(root->right, data);
    if(rightOutput != NULL){
        rightOutput->push_back(root->data);
        return rightOutput;
    }

    return NULL;
}
// delete vector after you are done
