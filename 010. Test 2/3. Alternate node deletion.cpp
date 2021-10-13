void deleteAlternateNodes(Node *head) {
    //Write your code here
    if(head == NULL){
        return;
    }

	Node *temp= head;
    while(temp && temp->next){
        Node *temp2= temp->next;
        temp->next= temp2->next;
		free(temp2);
        temp= temp->next;
    }
}
