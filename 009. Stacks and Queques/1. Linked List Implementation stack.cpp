
class Stack {
	// Define the data members
    Node *head;
    int counter;

   public:
    Stack() {
        // Implement the Constructor
        head= NULL;
        counter=0;

    }

	/*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function
        return counter;
    }

    bool isEmpty() {
        // Implement the isEmpty() function
        return (head == NULL);
    }

    void push(int element) {
        // Implement the push() function
        ++counter;
        Node *temp= new Node(element);
        temp->next= head;
        head= temp;
    }

    int pop() {
        // Implement the pop() function
        if(head == NULL){
            return -1;
        }

        --counter;
        int ans= head->data;
        Node *temp= head;
        head= head->next;
        delete temp;
        return ans;
    }

    int top() {
        // Implement the top() function
        if(head == NULL){
            return -1;
        }
        return head->data;
    }
};
