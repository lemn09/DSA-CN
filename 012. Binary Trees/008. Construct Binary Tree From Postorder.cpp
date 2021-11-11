BinaryTreeNode<int>* build(int *postOrder, int *inOrder, int pStart, int pEnd, int iStart, int iEnd){
    if(pStart > pEnd){
        return NULL;
    }
    BinaryTreeNode<int>* root= new BinaryTreeNode<int>(postOrder[pEnd]);

    int rootIndex=0;
    for(int i=iStart; i<=iEnd; i++){
    	if(inOrder[i] == root->data){
            rootIndex= i;
            break;
        }
    }

    int l_pStart= pStart;

    int l_iStart= iStart;
    int l_iEnd= rootIndex - 1;
	int l_pEnd= l_iEnd - l_iStart + l_pStart;

    int r_pStart= l_pEnd + 1;
    int r_pEnd= pEnd-1;
    int r_iStart= rootIndex+1;
    int r_iEnd= iEnd;

    root->left= build(postOrder, inOrder, l_pStart, l_pEnd, l_iStart, l_iEnd);
    root->right= build(postOrder, inOrder, r_pStart, r_pEnd, r_iStart, r_iEnd);
    return root;
}


BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
    // Write your code here
    return build(postorder, inorder, 0, postLength-1, 0, inLength - 1);
}
