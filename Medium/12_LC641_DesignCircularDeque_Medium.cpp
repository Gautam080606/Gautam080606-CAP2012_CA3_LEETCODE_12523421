class MyCircularDeque{
    int arr[1000];
    int front ,rear,size,k;
    public:
    MyCircularDeque(int k){
        this->k=k;
        front=0;
        rear=-1;
        size=0;
    } 
    bool insertFront(int value){
        if (isFull()) return false;
        front=(front-1+k)%k;
        arr[front]=value;
        if(size==0) rear = front;
        size++;
        return true;
    }
    bool insertLast(int value){
        if(isFull())return false;
        rear =(rear+1)%k;
        arr[rear]=value;
        if(size == 0)  front = rear;
        size++;
        return true;
        }
        bool deleteFront(){
            if(isEmpty()) return false;
            front = (front+1) % k;
            size--;
            return true;
        }
        bool deleteLast(){
            if(isEmpty()) return false;
            rear = (rear-1+k) % k;
            size--;
            return true;
        }
        int getFront(){
            if(isEmpty()) return -1;
            return arr[front];
        }
        int getRear(){
            if(isEmpty()) return -1;
            return arr[rear];
       }
       bool isEmpty(){
        return size==0;
       }
       bool isFull(){
        return size == k;
       }
};
