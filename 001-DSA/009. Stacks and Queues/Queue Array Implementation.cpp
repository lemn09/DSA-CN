#include<iostream>
using namespace std;
#define MAX_SIZE 10  //maximum size of the array that will store Queue.


class queque {

private:
    int arr[MAX_SIZE];
    int front, rear;            //front: exit, rear: entry (indice)

public:

    queque() {                  // default constructor
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return ((rear + 1) % MAX_SIZE == front);     //when position next to rear is front => queque is full
    }

    void enQueque(int element) {           // insertion
        cout << "\nEnqueuing \n";
        if (isFull()) {                    // if array is full, insertion can't happen
            cout << "Error: Queque is empty!!" << endl;
            return;
        } else if (isEmpty()) {              // if array is empty front and rear placed at zero
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;
        }
        arr[rear] = element;
    }

    void deQueue() {
        cout << "\nDequeuing \n";
        if (isEmpty()) {
            cout << "Error: Queue is Empty!!" << endl;
            return;
        } else if (front == rear) {          // when only 1 element is present in the queque, therefore after dequeuing the queque will become empty
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
    }

    int Front() {
        if (front == -1) {
            cout << "\nError: Queque is empty!!" << endl;
            return -1;
        }
        return arr[front];
    }

    int getSize() {
        return (isEmpty()) ? 0 : (rear - front + MAX_SIZE) % MAX_SIZE + 1;
    }

    void print()
    {
        // Finding number of elements in queue
        int count = (rear + MAX_SIZE - front) % MAX_SIZE + 1;
        cout << "Queue       : ";
        for (int i = 0; i < count; i++)
        {
            int index = (front + i) % MAX_SIZE; // Index of element while traversing circularly from front
            cout << arr[index] << " ";
        }
        cout << "\n\n";
    }
};

int main() {
    queque q1;
    cout << "\nSize: " << q1.getSize() << endl;
    q1.enQueque(10);
    q1.print();
    cout << "\nSize: " << q1.getSize() << endl;
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
    cout << endl << "Front: " << q1.Front() << endl;
    cout << "\nSize: " << q1.getSize() << endl;
    return 0;
}


