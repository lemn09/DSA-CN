Node *deleteNode(Node *head, int pos)
{
    // Write your code here.
    if(head == NULL){
        return head;
    }
    Node *temp=head;
    if(pos == 0){
        head= head->next;
        delete temp;
        return head;
    }
    for(int i=0; i<pos-1; i++){
        temp=temp->next;
    	if(temp == NULL){
            return head;
        }
    }
    Node *temp2= temp->next;
    if(temp2 == NULL){
        return head;
    }
    temp->next= temp2->next;
    delete temp2;
    return head;
}
