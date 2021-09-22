#include<iostream>
using namespace std;

template <typename T>

class node{
public:
    T data;
    node<T> *next;

    node(T data){
        this->next= NULL;
        this->data =data;
    }
};

template <typename T>

class Stack{
    node<T> *head;
    int counter;            //maintains the stack size

public:
    Stack(){
        head= NULL;
        counter= 0;
    }

    int getSize(){
        return counter;
    }

    bool isEmpty(){
        return (head == NULL);
    }

    void push(T element){
        node<T> *temp= new node<T>(element);
        temp->next= head;
        head= temp;
        ++counter;
    }

    T pop(){
        if(head == NULL){
            return 0;
        }

        T data= head->data;
        node<T> *temp= head;
        head= head->next;
        delete temp;
        --counter;
        return data;
    }

    T top(){
        return (head) ? head->data : 0;
    }

    void print(){
        cout<<"\nList: ";
        node<T> *temp= head;
        while(temp){
            cout<<temp->data<<' ';
            temp= temp->next;
        }
        cout<<endl;
    }
};

int main(){
    Stack<int> s1;
    cout<<"\nPushing 2 elements\n";
    s1.push(21);
    s1.print();
    s1.push(22);
    s1.print();

    cout<<"\nPop function demonstration\n";
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;

    cout<<"\nDemonstrating Isempty\n";
    cout<<s1.isEmpty();

    s1.push(20);
    s1.push(30);
    s1.push(40);
    cout<<endl;
    s1.print();

    cout<<"\nDemo for top function\n";
    cout<<s1.top();

    cout<<"\nDemo for size function\n";
    cout<<s1.getSize();
    cout<<"\nThe End\n";
    return 0;
}
