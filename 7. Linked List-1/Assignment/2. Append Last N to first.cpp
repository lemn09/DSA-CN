Node *appendLastNToFirst(Node *head, int n) {
	if (n == 0 || head == NULL) {
		return head;
	}
	Node *fast = head;
	Node *slow = head;
	Node *initialhead = head;
	for (int i = 0; i < n; i++) {
		fast = fast->next;
	}
	 while (fast->next != NULL) {
		slow = slow->next;
		fast = fast->next;
	}
	Node *temp = slow->next;
	slow->next = NULL;
	fast->next = initialhead;
	head = temp;
	return head;
}
