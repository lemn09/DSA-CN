vector<Node<int>*> result;
vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    if(root == NULL){
        return result;
    }
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        BinaryTreeNode<int>* f = q.front(); 
        if(f == NULL){
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        } else{
            Node<int>* root = new Node<int>(f->data);
            q.pop();
            if(f->left != NULL){
                q.push(f->left);
            }
            if(f->right != NULL){
                q.push(f->right);
            }
            Node<int>* curr = root;
            f = q.front();
            while(f != NULL){
                q.pop();
                if(f->left != NULL){
                    q.push(f->left);
                }
                if(f->right != NULL){
                    q.push(f->right);
                }
                Node<int>* newNode = new Node<int>(f->data);
                curr->next = newNode;
                curr = curr->next;
                f = q.front();
            }
            result.push_back(root);
        } 
    }
    return result;
}