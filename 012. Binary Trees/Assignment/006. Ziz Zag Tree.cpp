#include<stack>


void zigZagOrder(BinaryTreeNode<int> *root) {
    // Write your code here
    stack<BinaryTreeNode<int> *> s1;
    stack<BinaryTreeNode<int> *> s2;
    
    s1.push(root);
    while(!s1.empty() || !s2.empty()){
        
		if(!s1.empty()){
            while(!s1.empty()){
                BinaryTreeNode<int> *top= s1.top();
                s1.pop();
                cout<<top->data<<' ';
                if(top->left){
                    s2.push(top->left);
                }
                if(top->right){
                    s2.push(top->right);
                }
            }
            cout<<endl;
        }else if(!s2.empty()){
            while(!s2.empty()){
                BinaryTreeNode<int> *top= s2.top();
                s2.pop();
                if(top->right){
                    s1.push(top->right);
                }
                if(top->left){
                    s1.push(top->left);
                }
                cout<<top->data<<' ';
            }
            cout<<endl;
        }
    }
}