void printLevelWise(TreeNode<int>* root) {
    // Write your code here
    if(root == NULL){
        return;
    }

    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty()){
		TreeNode<int> *top= pendingNodes.front();
        pendingNodes.pop();

        cout<<top->data<<":";
        for(int i=0; i<top->children.size(); i++){
            cout<<top->children[i]->data;
            if(i+1 < top->children.size()){
                cout<<',';
            }
            pendingNodes.push(top->children[i]);
        }
        cout<<endl;
    }
}
