#include<iostream>
using namespace std;


// defining base for hashcode gneration
#define BASE 37

// initial bucket size
#define SIZE 5

// key: string 
template <typename V>
class MapNode{
    public:
        string key;
        V value;
        MapNode<V> *next;

        MapNode(string key, V value){
            next= NULL;
            this->key = key;
            this->value= value;
        }

        ~MapNode(){
            delete next; 
        }
};

// Collision Handling done using Separate Chaining( keys with same index occupy same spot) using array of linked lists
template <typename V>
class Map{
    private:
        MapNode<V> **buckets;                   // array of linked list
        int numBuckets;                         // size of array
        int count;                              // size of linked list associated with address at index i of array

    public:
        
        Map(){
            numBuckets= SIZE;
            count=0;
            buckets= new MapNode<V>*[numBuckets];
            for(int i=0; i<numBuckets; i++){
                buckets[i]= nullptr;
            }
        }
        
        ~Map(){
            for(int i=0; i<numBuckets; i++){
                delete buckets[i];
            }
            delete []buckets;
        }

        int size(){                     // return no. of keys or no. of linked list nodes created
            return count;
        }

    private:
        int getBucketIndex(string key){
            int HashCode= 0;
           int p= BASE;
           // currCoeff= (base)^i, where i is index of character, indexing starts from last char in this case
           int currCoeff= 0;                    

            // generating hashcode for string
            for(int i=key.size() - 1; i>=0; i--){
                HashCode+= key[i]*currCoeff;
                // to ensure hashcode doesn't cross the int limit
                HashCode%= numBuckets;                  
                currCoeff*= p;
                // to ensure currCoeff doesn't cross the int limit
                currCoeff%= numBuckets;
            }

            // returning compressed value
            return HashCode%numBuckets;
        }

        void rehash(){
            MapNode<V> **temp= buckets;
            buckets= new MapNode<V>*[2*numBuckets];
            numBuckets*=2;
            for(int i=0; i<numBuckets; i++){
                buckets[i]= NULL;
            }
            int oldBucketCount= numBuckets/2;
            count=0;
            for(int i=0; i<oldBucketCount; i++){
                MapNode<V> *head= temp[i];
                while(head != NULL){
                    insert(head->key, head->value);
                    head= head->next;
                }
            }

            for(int i=0; i<oldBucketCount; i++){
                MapNode<int> *head= temp[i];
                delete head;
            }
            delete []temp;
        }


    public:

        void insert(string key, V value){
            int keyIndex= getBucketIndex(key);
            MapNode<V> *currHead= buckets[keyIndex];

            // check if the key exists else generate new node for the key
            while(currHead != NULL){
                if(currHead->key == key){           // if key exists update the value
                    currHead->value= value;
                    return;
                }
                currHead= currHead->next;
            }

            //else if key doesn't exist create new Node
            currHead= buckets[keyIndex];
            MapNode<V> *node= new MapNode<V>(key, value);
            node->next= currHead;
            buckets[keyIndex]= node;                        // inserting new Node at head
            count++;                                        // count maintains no. of linked list nodes associated with head at index i of array
       
            double loadFactor= (double)count/numBuckets;
            if(loadFactor > 0.7){
                rehash();
            }
        }

        V remove(string key){
            int keyIndex= getBucketIndex(key);
            MapNode<V> *currHead= buckets[keyIndex];                            
            // prev node mainted to delete the required node
            MapNode<V> *prev= nullptr;
            
            // traversing the linked list
            while(currHead != nullptr){
                // deletion of node if key is found
                if(currHead->key == key){
                    V ans;
                    if(prev == nullptr){
                        buckets[keyIndex]= currHead->next;
                    }else{
                        prev->next= currHead->next;
                    }
                    // maintaning the value before deletion
                    ans= currHead->value;
                    // changing value of next, because destructor is recursive
                    currHead->next= NULL;
                    delete currHead;
                    count--;
                    return ans;
                }
                prev= currHead;
                currHead= currHead->next;
            }

            // key not found
            return 0;
        }

    V getValue(string key){
        int keyIndex= getBucketIndex(key);
        MapNode<V> *currHead= buckets[keyIndex];

        while(currHead != nullptr){
            if(currHead->key == key){
                return currHead->value;
            }
            currHead= currHead->next;
        }
        //if key not found
        return 0;
    }


    void print(){
        cout<<"\nMap\n";
        for(int i=0; i< numBuckets; i++){
            MapNode<V> *currHead= buckets[i];
            while(currHead != nullptr){
                cout<<"Key: "<<currHead->key<<" Value: "<<currHead->value<<endl;
                currHead= currHead->next;
            }
        }
    }

    double getLoadFactor(){
        return (double)count/numBuckets;
    }
};

int main(){
    Map<int> m;
    for(int i=0; i<20; i++){
        char ch= '0'+i;
        string key= "abc";
        key+= ch;
        int value= i+1;
        m.insert(key,value);
        cout<<m.getLoadFactor()<<endl;
    }

    m.print();
    return 0;
}
