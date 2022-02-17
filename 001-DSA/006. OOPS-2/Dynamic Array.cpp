#include<iostream>
using namespace std;

//#define SIZE 5

class DynamicArray{
    private:
        int *arr;
        int nextIndex;
        int capacity;

    public:
        DynamicArray(int size){                      // Constructor
            arr= new int[size]();
            nextIndex=0;
            capacity= size;
        }

        DynamicArray(DynamicArray const &a){            //Copy Constructor

            this->arr= new int[a.capacity];
            for(int i=0; i<a.nextIndex; i++){
                this->arr[i]= a.arr[i];
            }
            this->nextIndex= a.nextIndex;
            this->capacity= a.capacity;
        }

        void operator=(DynamicArray const &a){          //copy operator overload
            this->arr= new int[a.capacity];
            for(int i=0; i<a.nextIndex; i++){
                this->arr[i]= a.arr[i];
            }
            this->nextIndex= a.nextIndex;
            this->capacity= a.capacity;
        }

        void add(int element){
            if(nextIndex < capacity){
                this->arr[nextIndex++]= element;
                return;
            }
            int *newArr= new int[2*capacity];       //memory reallocation
            for(int i=0; i<nextIndex; i++){
                newArr[i]= this->arr[i];
            }
            newArr[nextIndex++]= element;
            arr= NULL;
            delete []arr;
            arr=newArr;
            capacity*=2;
        }

        int get(int index) const{                           // return value at given index
            if(index < nextIndex && index>0){
                return arr[index];
            }else{
                return -1;
             }
        }

        void add(int index, int element){            //function overloading, purpose of this function is to replace the element at the given index
            if(index<nextIndex){
                arr[index]= element;
            }else if(index == nextIndex){
                add(element);
            }else{
                return;
            }
        }

        void print() const{
            cout<<"Array: ";
            for(int i=0; i<nextIndex; i++){
                cout<<arr[i]<<' ';
            }
            cout<<endl;
        }
};


int main(){
    
    return 0;
}
