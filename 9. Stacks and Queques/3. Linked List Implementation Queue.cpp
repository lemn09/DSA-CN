class Queue {
	// Define the data members
    Node *head;
    Node *tail;
    int len;		// size of the list

   public:
    Queue() {
		// Implement the Constructor
		head= NULL;
        tail= NULL;
        len= 0;
    }

	/*----------------- Public Functions of Stack -----------------*/

	int getSize() {
		// Implement the getSize() function
     	return len;
	}

    bool isEmpty() {
		// Implement the isEmpty() function
		return (head == NULL && tail == NULL);
    }

    void enqueue(int data) {
		// Implement the enqueue() function
        Node *temp= new Node(data);
        len++;
        if(isEmpty()){
            head= temp;
            tail= temp;
        	return;
        }
        tail->next= temp;
        tail = temp;
	}

    int dequeue() {
        // Implement the dequeue() function
        Node *temp= head;
        int ans;
        if(isEmpty()){
            ans= -1;
            return ans;
        }else if(head == tail){
            ans= head->data;
            head = NULL;
            tail= NULL;
        }else{
            ans= head->data;
            head= head->next;
        }
        len--;
        delete temp;
        return ans;
    }

    int front() {
        // Implement the head() function
        if(isEmpty()){
            return -1;
        }
        return head->data;
    }
};
