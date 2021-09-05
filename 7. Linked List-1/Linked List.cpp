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
    Size(head);
}
