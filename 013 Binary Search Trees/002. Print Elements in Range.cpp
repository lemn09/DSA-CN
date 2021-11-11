void elementsInRangeK1K2(BinaryTreeNode<int>* root, int k1, int k2) {
	// Write your code here
    if(k2 < k1){
        elementsInRangeK1K2(root, k2, k1);
    }
    if(root == NULL){
        return;
    }
    
    if(root->data <= k2 && root->data >=k1){
        
        if(root->left){
            elementsInRangeK1K2(root->left, k1, k2);
        }
        cout<<root->data<<' ';
        if(root->right){
            elementsInRangeK1K2(root->right, k1, k2);
        }
        
    }else if(root->data > k2){
        if(root->left){
            elementsInRangeK1K2(root->left, k1, k2);
        }
    }else if(root->data < k1){
        if(root->right){
            elementsInRangeK1K2(root->right, k1, k2);
        }
    }
}