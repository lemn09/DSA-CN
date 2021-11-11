pair<Node<int> *, Node<int> *> helper(BinaryTreeNode<int> *root){
	if(root == NULL){
        
        pair<Node<int> *, Node<int> *> output;
        output.first= NULL;
        output.second=NULL;
        return output;
    }    
    
    
	pair<Node<int> *, Node<int> *> leftChild= helper(root->left);
    
    pair<Node<int> *, Node<int> *> rightChild= helper(root->right);
    
	
	if(leftChild.first == NULL){
        if(rightChild.first == NULL){
            pair<Node<int> *, Node<int> *> output;
            Node<int> *newNode= new Node<int>(root->data);
            output.first= newNode;
            output.second= newNode;
            
            return output;
        }else{
			Node<int> *newNode= new Node<int>(root->data);
            newNode->next= rightChild.first;
            pair<Node<int> *, Node<int> *> output;
            output.first= newNode;
            output.second= rightChild.second;
            return output;
        }
    }else if(rightChild.first == NULL){
        Node<int> *newNode= new Node<int>(root->data);
        leftChild.second->next= newNode;
        pair<Node<int> *, Node<int> *> output;
        output.first= leftChild.first;
        output.second= newNode;
        return output;
    }else{
        Node<int> *newNode= new Node<int>(root->data);
        leftChild.second->next= newNode;
        newNode->next= rightChild.first;
        pair<Node<int> *, Node<int> *> output;
        output.first= leftChild.first;
        output.second= rightChild.second;
        return output;
    }
}

Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
	// Write your code here
    pair<Node<int> *, Node<int> *> output= helper(root);
    if(output.second != NULL){
        output.second->next= NULL;
    }
   	
    return output.first;
}