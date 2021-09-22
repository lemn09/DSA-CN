#include<iostream>
#include<climits>
using namespace std;

#define SIZE 10

template <typename T>

class arrayStack{

private:
    T *data;
    int capacity;
    int nextIndex;

public:

    arrayStack(){                       // default Constructor
        capacity= SIZE;
        data= new T[SIZE];
        nextIndex= 0;
    }

    arrayStack(int len){            // Parameterized Constructor
        data= new T[len];
        capacity= len;
        nextIndex= 0;
    }

    T length(){
        return nextIndex;
    }

    bool isEmpty(){
        return nextIndex == 0;      // true: if stack is empty else false
    }

    void push(T el){
        if(nextIndex >= capacity){
            T *newArr= new T[2*capacity]();
            for(int i=0; i<capacity; i++){
                newArr[i]= data[i];
            }
            delete []data;
            data= newArr;
            capacity*=2;
        }
        data[nextIndex++]= el;
    }

    T pop(){
        if(nextIndex > 0){
            nextIndex--;
            return data[nextIndex];
        }else{
            cout<<"Stack is Empty"<<endl;
            return 0;
        }
    }

    T top(){
        if(nextIndex > 0){
            return data[nextIndex-1];
        }else{
            cout<<"Stack is Empty"<<endl;
            return INT_MIN;
        }
    }
};

int main(){
    arrayStack <float> s1(5);
    s1.push(5);
    s1.push(15);
    s1.push(1);
    s1.push(20);
    s1.push(10.256);

    cout<<"Top: "<<s1.top()<<endl;
    cout<<"\nPop: "<<s1.pop()<<endl;
    cout<<"Pop: "<<s1.pop()<<endl;
    cout<<"Pop: "<<s1.pop()<<endl;

    cout<<"\nLength: "<<s1.length()<<endl;
    return 0;
}
