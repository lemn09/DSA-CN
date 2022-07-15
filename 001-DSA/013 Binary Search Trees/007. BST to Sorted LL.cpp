void insertAtHead(Node<int> *&head, int data) {
    Node<int> *newNode = new Node<int>(data);
    newNode->next = head;
    head = newNode;
}

Node<int>* constructLinkedList(BinaryTreeNode<int>* root, Node<int> *head = NULL) {
    // Write your code here
    if (!root) {
        return NULL;
    }
    Node<int> *temp = constructLinkedList(root->right, head);
    head = (temp) ? temp : head;
    insertAtHead(head, root->data);
    temp = constructLinkedList(root->left, head);
    head = (temp) ? temp : head;
    return head;
}