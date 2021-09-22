#include<iostream>
using namespace std;

#define SIZE 10

template <typename T>

class Queue{
   T *data;
   int firstIndex;
   int nextIndex;
   int maxSize;

   public:
        Queue(){
            data= new T[SIZE];
            nextIndex= 0;
            firstIndex=-1;
            maxSize= SIZE;
        }

        Queue(int s){
            data= new T[s];
            firstIndex= 0;
            nextIndex= -1;
            maxSize= s;
        }

        bool isEmpty(){
            return (firstIndex == -1 && nextIndex == 0);
        }

        bool isFull(){
            return (nextIndex == firstIndex);
        }

        int getSize(){
            return (isEmpty()) ? 0 : ( nextIndex - firstIndex - 1 + maxSize)%maxSize+ 1;
        }

        void enQueue(T element){
            cout<<"\nEnqueuing: \n";
            if(isFull()){

//                cout<<"\nQueue is Full!!"<<endl;
//                return;
                    T *newArr= new T[maxSize*2];
                    int len= getSize();
                    for(int i=0; i<len; i++){
                        int index= (firstIndex + i)%maxSize;
                        newArr[i]= data[index];
                    }
                    delete []data;
                    data= newArr;
                    firstIndex=0;
                    nextIndex= len;
                    maxSize*=2;

            }else if(isEmpty()){
                firstIndex=0;
            }

            data[nextIndex]= element;
            nextIndex= (nextIndex + 1)% maxSize;
        }

        T deQueue(){
            cout<<"\nDequeuing : \n";
            if(isEmpty()){
                cout<<"\nError: Empty Queue\n";
                return 0;
            }
            int tempIndex= firstIndex;
            firstIndex= (firstIndex+1)%maxSize;
            if(getSize() == 0){
                firstIndex= -1;
                nextIndex= 0;
            }
            return data[tempIndex];
        }

        T Front(){
            if(isEmpty()){
                cout<<"\nError: Empty Queue!!\n";
                return 0;
            }
            return data[firstIndex];
        }

        void print(){
            int length= getSize();
            cout<<"Queue        : ";
            for(int i=0; i<length; i++){
                int index= (firstIndex + i)%maxSize;
                cout<<data[index]<<' ';
            }
            cout<<'\n';
        }
};

int main(){
    Queue<int> q1;
    cout<<"\nSize: "<<q1.getSize()<<endl;
    q1.enQueue(10);
    q1.print();
    cout<<"\nSize: "<<q1.getSize()<<endl;
    q1.enQueue(20);
    q1.print();
    q1.enQueue(30);
    q1.print();
    q1.enQueue(40);
    q1.print();
    q1.enQueue(50);
    q1.print();
    q1.enQueue(60);
    q1.print();
    q1.enQueue(70);
    q1.print();
    q1.enQueue(80);
    q1.print();
    q1.enQueue(90);
    q1.print();
    q1.enQueue(100);
    q1.print();
    q1.enQueue(110);
    q1.print();
    cout<<endl<<q1.deQueue()<<endl;
    q1.print();
    q1.enQueue(10);
    q1.print();
    cout<<endl<<"Front: "<<q1.Front()<<endl;
    cout<<"\nSize: "<<q1.getSize()<<endl;
    return 0;
}
