Node* reverse(Node* head){
    Node* previous=NULL;
    Node* next=NULL;
    Node* curr=head;
    while(curr != NULL){
        next = curr->next;
        curr->next = previous;
        previous = curr;
        curr = next;
    }
    return previous;
}

Node* NextLargeNumber(Node *head) {
    Node* reverseNumber = reverse(head);
    Node* curr = reverseNumber;
    Node* previous=NULL;
    int carry=1;
    while(curr != NULL){
        int sum = curr->data + carry;
        curr->data = sum%10;
        carry = sum/10;
        previous = curr;
        curr = curr->next;
    }
    if(carry > 0){
        Node* newNode = new Node(carry);
        previous->next = newNode;
    }
    return reverse(reverseNumber);
}
