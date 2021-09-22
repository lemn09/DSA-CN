#include<iostream>
using namespace std;
#define MAX_SIZE 10  //maximum size of the array that will store Queue.

// Creating a class named Queue.
//class Queue
//{
//private:
//	int A[MAX_SIZE];
//	int front, rear;
//public:
//	// Constructor - set front and rear as -1.
//	// We are assuming that for an empty Queue, both front and rear will be -1.
//	Queue()
//	{
//		front = -1;
//		rear = -1;
//	}
//
//	// To check wheter Queue is empty or not
//	bool IsEmpty()
//	{
//		return (front == -1 && rear == -1);
//	}
//
//	// To check whether Queue is full or not
//	bool IsFull()
//	{
//		return (rear+1)%MAX_SIZE == front ? true : false;
//	}
//
//	// Inserts an element in queue at rear end
//	void Enqueue(int x)
//	{
//		cout<<"Enqueuing "<<x<<" \n";
//		if(IsFull())
//		{
//			cout<<"Error: Queue is Full\n";
//			return;
//		}
//		if (IsEmpty())
//		{
//			front = rear = 0;
//		}
//		else
//		{
//		    rear = (rear+1)%MAX_SIZE;
//		}
//		A[rear] = x;
//	}
//
//	// Removes an element in Queue from front end.
//	void Dequeue()
//	{
//		cout<<"Dequeuing \n";
//		if(IsEmpty())
//		{
//			cout<<"Error: Queue is Empty\n";
//			return;
//		}
//		else if(front == rear )
//		{
//			rear = front = -1;
//		}
//		else
//		{
//			front = (front+1)%MAX_SIZE;
//		}
//	}
//	// Returns element at front of queue.
//	int Front()
//	{
//		if(front == -1)
//		{
//			cout<<"Error: cannot return front from empty queue\n";
//			return -1;
//		}
//		return A[front];
//	}
//	/*
//	   Printing the elements in queue from front to rear.
//	   This function is only to test the code.
//	   This is not a standard function for Queue implementation.
//	*/
//	void Print()
//	{
//		// Finding number of elements in queue
//		int count = (rear+MAX_SIZE-front)%MAX_SIZE + 1;
//		cout<<"Queue       : ";
//		for(int i = 0; i <count; i++)
//		{
//			int index = (front+i) % MAX_SIZE; // Index of element while travesing circularly from front
//			cout<<A[index]<<" ";
//		}
//		cout<<"\n\n";
//	}
//};
//int main()
//{
//	/*Driver Code to test the implementation
//	  Printing the elements in Queue after each Enqueue or Dequeue
//	*/
//   Queue Q; // creating an instance of Queue.
//   Q.Enqueue(2);  Q.Print();
//   Q.Enqueue(4);  Q.Print();
//   Q.Enqueue(6);  Q.Print();
//   Q.Dequeue();	  Q.Print();
//   Q.Enqueue(8);  Q.Print();
//}


class queque{

private:
    int arr[MAX_SIZE];
    int front,rear;             //front: exit, rear: entry (indice)

public:

    queque(){                   // default constructor
        front=-1;
        rear=-1;
    }

    bool isEmpty(){
        return (front == -1 && rear == -1);
    }

    bool isFull(){
       return ((rear+1)%MAX_SIZE == front);         //when position next to rear is front => queque is full
    }

    void enQueque(int element){            // insertion
        cout<<"\nEnqueuing \n";
        if(isFull()){                      // if array is full, insertion can't happen
            cout<<"Error: Queque is empty!!"<<endl;
            return;
        }else if(isEmpty()){                // if array is empty front and rear placed at zero
            front=rear=0;
        }else{
            rear= (rear+1)%MAX_SIZE;
        }
        arr[rear]= element;
    }

    void deQueue(){
        cout<<"\nDequeuing \n";
        if(isEmpty()){
            cout<<"Error: Queue is Empty!!"<<endl;
            return;
        }else if(front == rear){            // when only 1 element is present in the queque, therefore after dequeuing the queque will become empty
            front = -1;
            rear= -1;
        }else{
            front= (front + 1)%MAX_SIZE;
        }
    }

    int Front(){
        if(front == -1){
            cout<<"\nError: Queque is empty!!"<<endl;
            return -1;
        }
        return arr[front];
    }

    int getSize(){
        return (isEmpty()) ? 0 : (rear - front + MAX_SIZE)%MAX_SIZE + 1;
    }

    void print()
	{
		// Finding number of elements in queue
		int count = (rear+MAX_SIZE-front)%MAX_SIZE + 1;
		cout<<"Queue       : ";
		for(int i = 0; i <count; i++)
		{
			int index = (front+i) % MAX_SIZE; // Index of element while travesing circularly from front
			cout<<arr[index]<<" ";
		}
		cout<<"\n\n";
	}
};

int main(){
    queque q1;
    cout<<"\nSize: "<<q1.getSize()<<endl;
    q1.enQueque(10);
    q1.print();
    cout<<"\nSize: "<<q1.getSize()<<endl;
    q1.enQueque(20);
    q1.print();
    q1.enQueque(30);
    q1.print();
    q1.enQueque(30);
    q1.print();
    q1.enQueque(30);
    q1.print();
    q1.enQueque(30);
    q1.print();
    q1.enQueque(30);
    q1.print();
    q1.enQueque(30);
    q1.print();
    q1.enQueque(30);
    q1.print();
    q1.enQueque(30);
    q1.print();
    q1.enQueque(30);
    q1.print();
    q1.deQueue();
    q1.print();
    q1.enQueque(30);
    q1.print();
    cout<<endl<<"Front: "<<q1.Front()<<endl;
    cout<<"\nSize: "<<q1.getSize()<<endl;
    return 0;
}


