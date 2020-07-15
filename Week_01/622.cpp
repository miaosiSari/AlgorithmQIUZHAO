class MyCircularQueue {
private:
    int cap;
    int cur;
    int rear;
    int front;
    int* p;
    int addm(int x, int t){
        int y = (x + t)%cap;
        if(y < 0) y += cap;
        return y;
    }

public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        cap = k;
        cur = 0;
        rear = 0;
        front = 0;
        p = new int[cap];
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(isFull()) return false;
        ++cur;
        p[rear] = value;
        rear = addm(rear, 1);
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(isEmpty()) return false;
        --cur;
        front = addm(front, 1);
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(isEmpty()) return -1;
        return p[front];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(isEmpty()) return -1;
        int y = addm(rear, -1);
        return p[y];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return (cur == 0);
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return (cur == cap);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */