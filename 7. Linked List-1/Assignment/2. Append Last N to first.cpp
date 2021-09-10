/**
    T(n) : O(n)
    S(n) : O(1)
**/


Node *appendLastNToFirst(Node *head, int n)
{
    //Write your code here
    if(head == NULL || n==0){
        return head;
    }
    Node *fast=head,*slow=head;
    for(int i=0; i<n; i++){
        fast= fast->next;
        if(fast->next == NULL){
            return head;
        }
    }

    while(fast->next){
        slow=slow->next;
        fast= fast->next;
    }

    Node *temp= head;
    head= slow->next;
    fast->next= temp;
    slow->next= NULL;
    return head;
}
