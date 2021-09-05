int length(Node *head)
{
    //Write your code here
    int count=0;
    while(head){
        ++count;
        head=head->next;
    }
    return count;
}
