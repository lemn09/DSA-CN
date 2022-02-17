#include<iostream>
using namespace std;

template <typename T>

class node{
    public:
    node<T> *next;
    T data;

    node(T data){
        this->data= data;
        this->next= NULL;
    }
};

template <typename T>

class Queue{
    node<T> *front;         // exit
    node<T> *rear;          // entry
    int len;                // size of the list

public:
    Queue(){
        front= NULL;
        rear= NULL;
        len= 0;
    }

    bool isEmpty(){
        return (front == NULL && rear == NULL);
    }

    int getSize(){
        return len;
    }

    void enqueue(T x){
        cout<<"\nEnqueuing : \n";
        node<T> *temp= new node<T>(x);
        temp->next= NULL;
        len++;
        if(front == NULL && rear == NULL){
            front= rear = temp;
            return;
        }
        rear->next= temp;
        rear= temp;
    }

    T dequeue(){
        node<T> *temp= front;
        int ans;
        cout<<"\nDequeuing : \n";
        if(isEmpty()){
            cout<<"\nError: Queue is empty!!"<<endl;
            return 0;
        }else if(front == rear){
            ans= front->data;
            front= rear= NULL;
        }else{
            ans= front->data;
            front= front->next;
        }
        delete temp;
        len--;
        return ans;
   }

    T Front(){
        if(isEmpty()){
            return 0;
        }
        return front->data;
    }

    void print(){
        node<T> *head= front;
        cout<<"\nList   : ";
        while(head){
            cout<<head->data<<' ';
            head= head->next;
        }
        cout<<'\n';
    }
};

int main(){
    Queue<int> q1;
    q1.enqueue(10);     q1.print();
    cout<<"\nSize of the list   : "<<q1.getSize()<<endl;
    q1.enqueue(20);     q1.print();
    cout<<"\nSize of the list   : "<<q1.getSize()<<endl;
    q1.enqueue(30);     q1.print();
    cout<<"\nSize of the list   : "<<q1.getSize()<<endl;
    cout<<"\nFront  : "<<q1.Front();
    q1.enqueue(40);     q1.print();
    cout<<"\nSize of the list   : "<<q1.getSize()<<endl;
    q1.enqueue(50);     q1.print();
    cout<<"\nSize of the list   : "<<q1.getSize()<<endl;
    q1.enqueue(60);     q1.print();
    cout<<"\nFront  : "<<q1.Front();
    cout<<"\nSize of the list   : "<<q1.getSize()<<endl;
    cout<<q1.dequeue();       q1.print();
    cout<<q1.dequeue();       q1.print();
    cout<<q1.dequeue();       q1.print();
    cout<<q1.dequeue();       q1.print();
    cout<<q1.dequeue();       q1.print();
    cout<<q1.dequeue();       q1.print();
    cout<<"\nisEmpty(): "<<q1.isEmpty()<<endl;
    cout<<"\nsize: "<<q1.getSize();
    return 0;
}
