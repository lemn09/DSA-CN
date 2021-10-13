template <typename T>
class SecondLargestReturnType {
    public:
        TreeNode<T> *largest;
        TreeNode<T> *secondLargest;

        SecondLargestReturnType(TreeNode<T> *first, TreeNode<T> *second){
            this->largest= first;
            this->secondLargest= second;
        }
};

SecondLargestReturnType<int> *getSecondLargestNodeHelper(TreeNode<int> *root){
    if(root == NULL){
        return new SecondLargestReturnType<int>(NULL,NULL);
    }

    SecondLargestReturnType<int> *ans= new SecondLargestReturnType<int>(root, NULL);

    for(int i=0; i<root->children.size(); i++){
        SecondLargestReturnType<int> *childAns= getSecondLargestNodeHelper(root->children[i]);

        if(childAns->largest->data > ans->largest->data){
            if(childAns->secondLargest == NULL){
                ans->secondLargest= ans->largest;
                ans->largest= childAns->largest;
            }else{
                if(childAns->secondLargest->data > ans->largest->data){
                    ans->secondLargest= childAns->secondLargest;
                    ans->largest= childAns->largest;
                }else{
                    ans->secondLargest= ans->largest;
                    ans->largest= childAns->largest;
                }
            }
        }

        else{
            if(ans->largest->data != childAns->largest->data && (ans->secondLargest == NULL || childAns->largest->data > ans->secondLargest->data) ){
                ans->secondLargest= childAns->largest;
            }
        }
    }

    return ans;
}

TreeNode<int> *getSecondLargestNode(TreeNode<int> *root){
    return getSecondLargestNodeHelper(root)->secondLargest;
}
