class Deque {
    // Complete this class
    int *arr;
    int front;
    int rear;
    int capacity;

    public:
    	Deque(int size){
            arr= new int[size]();
            capacity= size;
            front= -1;
            rear= -1;
        }

    	bool isEmpty(){
            return (rear == -1 && front == -1);
        }

    	bool isFull(){
            return (rear+1)%capacity == front;
        }

    	int getSize(){
            return (isEmpty()) ? 0 : (rear - front + capacity)%capacity + 1;
        }

    	void insertRear(int data){
            if(isFull()){
                cout<<-1<<endl;
                return;
            }else if(isEmpty()){
                front= rear= 0;
            }else{
                rear= (rear + 1)%capacity;
            }
            arr[rear]= data;
        }

    	void insertFront(int data){
            if(isFull()){
                cout<<-1<<endl;
                return;
            }else if(isEmpty()){
                front= rear= 0;
            }else{
                front= ((front - 1)%capacity + capacity)%capacity;
            }

            arr[front]= data;
        }

    	void deleteFront(){
            if(isEmpty()){
                cout<<-1<<endl;
                return;
            }else if(front == rear){
                front= rear= -1;
            }else{
                front= (front + 1)%capacity;
            }
        }

    	void deleteRear(){
            if(isEmpty()){
                cout<<-1<<endl;
                return;
            }else if(front == rear){
                front= rear= -1;
            }else{
                rear= ((rear-1)+ capacity)%capacity;
            }
        }

    	int getFront(){
            if(isEmpty()){
                return -1;
            }
            return arr[front];
        }

    	int getRear(){
            if(isEmpty()){
                return -1;
            }
            return arr[rear];
        }
};
