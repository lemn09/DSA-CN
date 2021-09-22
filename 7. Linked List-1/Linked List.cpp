#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node *next;

    node(int data){
        this->data= data;
        next= NULL;
    }
};

void Size(node* const &head){
    node *temp= head;
    int size=0;
    while(temp){
        temp=temp->next;
        ++size;
    }
    cout<<"\nSize: "<<size<<endl;
    return;
}
void insertAtHead(node* &head, int data){
    node *temp= new node(data);
    temp->next=head;
    head=temp;
}

void insertAtTail(node* &head, int data){
    node *temp= new node(data);
    if(head == NULL){
        head= temp;
        return;
    }else{
        node *temp2= head;
        while(temp2->next){             //traversing to the last element
            temp2=temp2->next;
        }
        temp2->next= temp;
    }
}

void printNode(node* const &head){
    if(head == NULL){
        return;
    }
    int index;
    cout<<"\nEnter the index(indexing starts from zero): ";
    cin>>index;
    node *temp= head;
    for(int j=0; j<index; j++){
        temp=temp->next;
        if(temp == NULL){
            return;
        }
    }
    cout<<temp->data;
    return;
}

void print(node* const &head){
    if(head == NULL){
        return;
    }
    node *temp=head;
    cout<<"List: ";
    while(temp){
        cout<<temp->data<<' ';
        temp=temp->next;
    }
    cout<<endl;
}


node *mergeTwoSortedLinkedLists(node *head1, node *head2){
    node *fH=NULL,*fTail=NULL;
    node *minAdd= (head1->data < head2->data) ? head1 : head2;
    fH=minAdd;
    fTail=minAdd;
    node *temp1= head1->next, *temp2= head2;
    while(temp1 && temp2){
        if(temp1->data < temp2->data){
            fTail->next= temp1;
            fTail=fTail->next;
            temp1=temp1->next;
        }else{
            fTail->next= temp2;
            fTail= fTail->next;
            temp2=temp2->next;
        }
    }

    while(temp1){
        fTail->next= head1;
    }
    while(temp2){
        fTail->next= head2;
    }
    return fH;
}

void fun(node *someNode)
{
   cout<<"\nExperiment: ";
   node **var= *someNode;

}

int main(){
    int choice=1,data;
    node *head=NULL;
    while(choice!=3){
        cout<<"1.Insert At Tail \n2.Insertion at head \n3.End Insertion \nEnter your choice: ";
        cin>>choice;
        switch(choice){
            case 1: cout<<"\nEnter the element: ";
                    cin>>data;
                    insertAtTail(head,data);
                    break;
            case 2: cout<<"\nEnter the element: ";
                    cin>>data;
                    insertAtHead(head,data);
                    break;
            case 3: break;
            default: cout<<"\nInvalid Choice\n";
        }
        cout<<endl;
    }
    print(head);
   // printNode(head);
   // Size(head);
   node *head2= NULL;
   choice=1;
   cout<<"\nSecond Head\n";
   while(choice!=3){
        cout<<"1.Insert At Tail \n2.Insertion at head \n3.End Insertion \nEnter your choice: ";
        cin>>choice;
        switch(choice){
            case 1: cout<<"\nEnter the element: ";
                    cin>>data;
                    insertAtTail(head2,data);
                    break;
            case 2: cout<<"\nEnter the element: ";
                    cin>>data;
                    insertAtHead(head2,data);
                    break;
            case 3: break;
            default: cout<<"\nInvalid Choice\n";
        }
        cout<<endl;
    }
    print(head2);
    node *newHead= mergeTwoSortedLinkedLists(head,head2);
    print(newHead);
    fun(head);
    return 0;
}
