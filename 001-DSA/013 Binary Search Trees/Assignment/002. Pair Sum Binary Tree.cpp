#include<algorithm>

vector<int>* preOrderTraversal(BinaryTreeNode<int>* root){
    vector<int>* ans = new vector<int>();
    if(root == NULL){
        return ans;
    }
    ans->push_back(root->data);
    vector<int>* left = preOrderTraversal(root->left);
    vector<int>* right = preOrderTraversal(root->right);
    for(int i=0; i<left->size(); i++){
        ans->push_back(left->at(i));
    }
    for(int i=0; i<right->size(); i++){
        ans->push_back(right->at(i));
    }
    return ans;
}

void pairSum(BinaryTreeNode<int> *root, int sum) {
	vector<int>* arr = preOrderTraversal(root);
    sort(arr->begin(), arr->end());
    int start=0, end=arr->size()-1;
    while(start < end){
        if(arr->at(start) + arr->at(end) == sum){
            cout << arr->at(start) << " " << arr->at(end) << endl;
            start++;
            end--;
        } else if(arr->at(start) + arr->at(end) < sum){
            start++;
        } else {
            end--;
        }
    }
}