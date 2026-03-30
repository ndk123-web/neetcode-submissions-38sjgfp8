class MyCircularQueue {
private:
    deque<int> dq;
    int size;
public:
    MyCircularQueue(int k) {   
        size = k;      
    }
    
    bool enQueue(int value) {
        if (dq.size() == size) {
            return false;
        }
        dq.push_back(value);
        return true;
    }
    
    bool deQueue() {
        if (dq.size() != 0) {
            dq.pop_front();
            return true;
        }
        return false;
    }
    
    int Front() {
        if (dq.size() != 0) return dq.front();
        return -1;
    }
    
    int Rear() {
        if (dq.size() != 0) return dq.back();
        return -1;
    }
    
    bool isEmpty() {
        return dq.size() == 0;   
    }
    
    bool isFull() {
        return dq.size() == size;
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