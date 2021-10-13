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

// Alternate Approach : S(n): O(1)
/**
Node* reverse(Node* head){
    Node* previous=NULL;
    Node* current=head;
    Node* next=NULL;
    while(current != NULL){
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    head = previous;
    return head;
}

bool isPalindrome(Node *head){
    if(head == NULL || head->next == NULL){
        return true;
    }
    Node* slow = head;
    Node* fast = head;
    Node* previous=NULL;
    while(fast != NULL && fast->next != NULL){
        previous = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    previous->next = NULL;
    Node* reverseHead = reverse(slow);
    Node* temp1 = head;
    Node* temp2 = reverseHead;
    while(temp1 != NULL){
        if(temp1->data != temp2->data){
            return false;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return true;
}

**/

/** Another Alternate Approach
int length(Node *head){
    int count=0;
    while(head){
        count++;
        head=head->next;
    }
    return count;
}

void reverse(Node* &head){
	Node *current= head, *prev= NULL, *next=NULL;
    while(current){
        next= current->next;
        current->next= prev;
        prev= current;
        current= next;
    }
    head= prev;
}

bool isPalindrome(Node *head)
{
    if(head == NULL){
        return true;
    }
    //Write your code here
    int len= length(head);
    int n= (len%2) ?  len/2 : (len/2 - 1);
    Node *temp1= head;
    for(int i=0; i<n; i++){
        temp1= temp1->next;
    }
    Node *temp2= temp1->next;
    reverse(temp2);
    temp1->next= NULL;
    temp1=head;
    while(temp1 && temp2){
        if(temp1->data != temp2->data){
            return false;
        }
        temp1= temp1->next;
        temp2= temp2->next;
    }
    return true;
} **/
