/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/
void insertAtTail(Node* &head, int data){
    Node *temp= new Node(data);
    if(head == NULL){
        head= temp;
    }else{
        Node *temp2= head;
        while(temp2->next){
            temp2=temp2->next;
        }
        temp2->next=temp;
    }
    return;
}

void print(Node* const &head){
	cout<<"Linked List: ";
    Node* temp= head;
    while(temp){
        cout<<temp->data<<' ';
        temp=temp->next;
    }
    cout<<endl;
}

bool isPalindrome(Node *head)
{
    //Write your code here
    Node *temp= head;
    Node *newNode = NULL;
    while(temp){
        insertAtTail(newNode,temp->data);
        temp= temp->next;
    }
   // print(newNode);

    Node *current=head, *next=NULL,*prev=NULL;
    while(current){
        next= current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
    //print(head);

    temp= head;
    Node *temp2= newNode;
    while(temp){
        if(temp->data != temp2->data){
            return false;
        }
        temp=temp->next;
        temp2=temp2->next;
    }
    return true;
}
