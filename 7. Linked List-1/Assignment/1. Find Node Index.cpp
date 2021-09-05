int findNode(Node *head, int n){
    // Write your code here.
    int count=0;
    while(head){
        if(head->data == n){
            return count;
        }
        head=head->next;
        ++count;
    }
    return -1;
}
