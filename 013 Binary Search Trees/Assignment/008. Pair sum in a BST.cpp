#include<vector>
#include<algorithm>

void insert(BinaryTreeNode<int> *root, vector<int> *arr){
    if(root == NULL){
        return;
    }
    
    arr->push_back(root->data);
    insert(root->right, arr);
    insert(root->left, arr);
}

void printNodesSumToS(BinaryTreeNode<int> *root, int sum) {
    // Write your code here
    vector<int> *arr= new vector<int>;
    insert(root, arr);
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