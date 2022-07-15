#include<iostream>
#include<vector>
using namespace std;

#define SWAP(a,b,c) ((c)= (a), (a)= (b), (b)= (c))

// min pq
class PriorityQueue {
private:
    vector<int> pq;

public:
    PriorityQueue() {
    }

    bool isEmpty() {
        return pq.empty();
    }

    int getSize() {
        return pq.size();
    }

    int getMin() {
        if (pq.empty()) {
            return 0;
        }
        return pq[0];
    }

    // void Insert(int element){
    //     if(isEmpty()){
    //         pq.push_back(element);
    //     }else{
    //         pq.push_back(element);
    //         int childIndex= pq.size() -1;
    //         int parentIndex= (childIndex - 1) /2;
    //         while(childIndex > 0 && parentIndex > 0 && pq[childIndex] < pq[parentIndex]){
    //             int temp= pq[childIndex];
    //             pq[childIndex]= pq[parentIndex];
    //             pq[parentIndex]= temp;
    //             childIndex= parentIndex;
    //             parentIndex= (childIndex - 1)/2;
    //         }
    //     }
    // }

    void insert(int element) {
        if (pq.empty()) {
            pq.push_back(element);
            return;
        } else {
            // insert element at end upheapify till min. heap condition isn't satified
            pq.push_back(element);
            int childIndex = pq.size() - 1;

            // upHeapify till heap property is satisfied
            while (childIndex > 0) {
                int parentIndex = (childIndex - 1) / 2;
                if (pq.at(childIndex) < pq.at(parentIndex)) {
                    int temp = pq[childIndex];
                    pq[childIndex] = pq[parentIndex];
                    pq[parentIndex] = temp;
                } else {
                    break;                              // when heap property is satisfied we stop
                }
                childIndex = parentIndex;
            }
        }
    }

    void print() {
        for (int i = 0; i < pq.size(); i++) {
            cout << pq[i] << ' ';
        }
        cout << endl;
    }
    // int removeMin(){

    //     if(pq.empty()){
    //         cout<<"Error: Empty Queue!!"<<endl;
    //         return 0;
    //     }else if(pq.size() == 1){
    //         int temp= pq[0];
    //         pq.pop_back();
    //         return temp;
    //     }else{
    //         int ans= pq[0];

    //         pq[0]= pq.back();
    //         pq.pop_back();


    //         // down heapify
    //         int parentIndex= 0;
    //         int lastIndex= pq.size() - 1;
    //         while(parentIndex < lastIndex){
    //             int rightChildIndex= (parentIndex * 2) + 2;
    //             int leftChildIndex= (parentIndex * 2) + 1;
    //             if(rightChildIndex > lastIndex && leftChildIndex > lastIndex){
    //                 break;
    //             }

    //             if( leftChildIndex <= lastIndex (rightChildIndex > lastIndex || pq[leftChildIndex] <= pq[rightChildIndex]) && pq[parentIndex] >= pq[leftChildIndex]){
    //                 int temp= pq[leftChildIndex];
    //                 pq[leftChildIndex]= pq[parentIndex];
    //                 pq[parentIndex]= temp;
    //                 parentIndex= leftChildIndex;
    //             }else if(rightChildIndex <= lastIndex && (leftChildIndex > lastIndex || pq[rightChildIndex] <= pq[leftChildIndex]) && pq[parentIndex] >= pq[rightChildIndex]){
    //                 int temp= pq[rightChildIndex];
    //                 pq[rightChildIndex]= pq[parentIndex];
    //                 pq[parentIndex]= temp;
    //                 parentIndex= rightChildIndex;
    //             }else{
    //                 break;
    //             }

    //         }
    //         return ans;
    //     }
    //}

    int removeMin() {
        if (pq.empty()) {
            return 0;
        } else if (pq.size() == 1) {
            int ans = pq.back();
            pq.pop_back();
            return ans;
        } else {
            int ans = pq[0];
            pq[0] = pq.back();
            pq.pop_back();

            int parentIndex = 0;
            int minIndex = 0;

            while (parentIndex < pq.size() - 1) {
                minIndex = parentIndex;
                int leftChildIndex = parentIndex * 2  + 1;
                int rightChildIndex = parentIndex * 2 + 2;

                if ( leftChildIndex < pq.size() && pq[leftChildIndex] < pq[minIndex]) {
                    minIndex = leftChildIndex;
                }
                if ( rightChildIndex < pq.size() && pq[rightChildIndex] < pq[minIndex]) {
                    minIndex = rightChildIndex;
                }

                if (minIndex == parentIndex) {
                    break;
                }
                int temp;
                SWAP(pq[parentIndex], pq[minIndex], temp);
                parentIndex = minIndex;
            }
            return ans;
        }

    }
};

int main() {
    PriorityQueue p1;
    p1.insert(20);
    p1.insert(7);
    p1.insert(15);
    p1.insert(18);
    p1.insert(5);
    p1.insert(9);

    p1.print();


    while (!p1.isEmpty()) {
        cout << p1.removeMin() << endl;
    }

    return 0;
}


