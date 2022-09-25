class MyCircularQueue {
public:
    int maxSize, front = 0, rear = -1;
    vector<int> v;
    
    MyCircularQueue(int k) {
        v.resize(k);
        maxSize = k;
    }
    bool enQueue(int val) {
        if (isFull()) return false;
        rear = (rear + 1) % maxSize;
        v[rear] = val;
        return true;
    }
    bool deQueue() {
        if (isEmpty()) return false;
        if (front == rear) front = 0, rear = -1;
        else front = (front + 1) % maxSize;
        return true;
    }
    int Front() {
        return isEmpty() ? -1 : v[front];
    }
    int Rear() {
        return isEmpty() ? -1 : v[rear];
    }
    bool isEmpty() {
        return rear == -1;
    }
    bool isFull() {
        return !isEmpty() and (rear + 1) % maxSize == front;
    }

};
