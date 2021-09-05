Node* insertNode(Node *head, int i, int data) {
	// Write your code here
    if(i == 0){
        Node *temp= new Node(data);
        temp->next= head;
        return temp;
    }
    if(i == 1){
		if(head == NULL){
            return head;
        }
        Node *temp= new Node(data);
        Node *temp2= head;
        if(temp2->next == NULL){
            return head;
        }
        temp->next= temp2->next;
        temp2->next= temp;
        return head;
    }
    if(head == NULL){
        return head;
    }
    Node *temp= insertNode(head->next,i-1,data);
	return head;
}
