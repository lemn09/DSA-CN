// first 2 submissions were wrong when one of the node to be swapped is head
Node *swapNodes(Node *head, int i, int j){
	if(i == j){ 
		return head;
	}
	Node *currentNode = head, *prev = NULL; 
	Node *firstNode = NULL, *secondNode =NULL, *firstNodePrev= NULL, *secondNodePrev=NULL;
	int pos=0;
	while(currentNode != NULL){
		if(pos == i){
			firstNodePrev= prev;
			firstNode= currentNode;
		}else if(pos == j){
			secondNodePrev= prev;
			secondNode= currentNode;
		}
		prev= currentNode;
		currentNode= currentNode->next;
		pos++;
	}
	if(firstNodePrev){
		firstNodePrev->next= secondNode;
	}else{
		head= secondNode;
	}

	if(secondNodePrev){
		secondNodePrev->next= firstNode;
	}else{	
		head= firstNode;
	}

	Node *currentFirstNode= secondNode ->next;
	secondNode->next= firstNode->next;
	firstNode->next= currentFirstNode;

	return head;
}