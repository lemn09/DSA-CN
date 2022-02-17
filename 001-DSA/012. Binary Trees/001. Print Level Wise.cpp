#include<queue>
void printLevelWise(BinaryTreeNode<int> *root) {
	// Write your code here
    if(root == NULL){
        return;
    }

    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        BinaryTreeNode<int> *front= pendingNodes.front();
        pendingNodes.pop();

        cout<<front->data<<':';
        if(front->left){
        	cout<<"L:"<<front->left->data<<',';
            if(front->left->data != -1){
                pendingNodes.push(front->left);
        	}
        }else{
            cout<<"L:"<<-1<<',';
        }

        if(front->right){
            cout<<"R:"<<front->right->data;
            if(front->right->data != -1){
                pendingNodes.push(front->right);
            }
    	}else{
            cout<<"R:"<<-1;
        }
        cout<<endl;
    }
}
