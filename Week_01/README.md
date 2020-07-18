# 学习笔记

使用addfirst和addlast这一套API实现循环双端队列:

一定要注意去模运算。假设rear = 0, k = 3 删除尾部元素时, 如果不慎rear = (rear - 1)%k; 则rear = -1(不是想当然的2), 下标会溢出! 

没看题解实现出来的，提交了3次才成功。执行用时48ms, 超过97.31%的用户。内存消耗15.4MB，超过100%用户。

```c++
class MyCircularDeque {
private:
    int cap;
    int cur;
    int rear;
    int front;
    int* p;
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        cap = k;
        cur = 0;
        rear = 0;
        front = 0;
        p = new int[cap];
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        //cout << "insertFront\n";
        if(cur < cap)
        {
            ++cur;
            front = (front - 1)%cap;
            if(front == -1)
                front += cap;
            p[front] = value;
            return true;
        }
        return false;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        cout << "insertLast\n";
        if(cur < cap)
        {
            ++cur;
            cout << rear << endl;
            p[rear] = value;
            rear = (rear + 1)%cap;
            return true;
        }
        return false;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        //cout << "deleteFront\n";
        if(cur == 0) return false;
        --cur;
        front = (front + 1)%cap;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        //printf("deleteLast");
        if(cur == 0) return false;
        --cur;
        rear = (rear - 1)%cap;
        if(rear < 0) rear += cap;
        return true; 
    } 
    
    /** Get the front item from the deque. */
    int getFront() {
        //printf("getFront\n");
        if(isEmpty()) return -1;
        return p[front];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        //printf("getRear\n");
        if(isEmpty()) return -1;
        int l = rear - 1 >= 0 ? rear - 1: cap - 1;
        cout << l << endl;
        return p[l];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        //printf("isEmpty\n");
        return (cur == 0);
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        printf("isFull\n");
        return (cur == cap);
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
```

