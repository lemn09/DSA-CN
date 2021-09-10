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

/** Alternate Method: Recursive Solution **/
int findNode(Node *head, int n){
    // Write your code here.
    if(head == NULL){
        return -1;
    }

    if(head->data == n){
        return 0;
    }else{
        int smallOutput= findNode(head->next,n);
    	return (smallOutput == -1) ? -1 : 1+smallOutput;
    }
}
