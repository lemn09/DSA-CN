BinaryTreeNode<int>* build(int *preOrder, int preStart, int preEnd, int *inOrder, int inStart, int inEnd){
    if(inStart > inEnd){
        return NULL;
    }

    BinaryTreeNode<int> *root= new BinaryTreeNode<int>(preOrder[preStart]);



    // if(preStart == preEnd && inStart == inEnd){
    //     root->left = NULL;
    //     root->right = NULL;
    // }else{
    	int i;
        for( i=inStart; i<= inEnd; i++){
            if(inOrder[i] == root->data){
                break;
            }
        }
    	root->left= build(preOrder, 1+preStart, i - inStart + preStart, inOrder, inStart, i-1);
    	root->right= build(preOrder, i- inStart + preStart + 1, preEnd,inOrder, i+1, inEnd);
    //}
    return root;
}


BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    // Write your code here
    return build(preorder, 0, preLength -1 , inorder, 0, inLength - 1);
}
