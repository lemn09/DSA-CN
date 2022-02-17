Node *removeDuplicates(Node *head)
{
    //Write your code here
    if(head == NULL){
        return head;
    }
    if(head->next == NULL){
        return head;
    }
    if(head->data == head->next->data){
        Node *temp= head->next;
        head->next= temp->next;
        delete temp;
        head= removeDuplicates(head);
    }else{
        head->next= removeDuplicates(head->next);
    }
    return head;
}
