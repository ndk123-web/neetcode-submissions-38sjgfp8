struct Node {
    int data;
    Node* next;

    Node(int data) { this->data = data; this->next = nullptr;}
};

class MyCircularQueue {
private:
    int size;
    Node* front = nullptr;
    Node* back = nullptr;
    int currcnt = 0;

public:
    MyCircularQueue(int k) { size = k; }

    bool enQueue(int value) {
        if (currcnt == size) {
            return false;
        }
        Node* newback = new Node(value);
        if (back == nullptr) {
            back = newback;
            front = newback;
        } else {
            back->next = newback;
            back = back->next;
        }
        currcnt++;
        return true;
    }

    bool deQueue() {
        if (currcnt == 0) {
            return false;
        }
        if (front != nullptr && front->next == nullptr) {
            front = nullptr;
            back = nullptr;
        } else {
            Node* temp = front->next;
            front->next = nullptr;
            front = temp;
        }
        currcnt--;
        return true;
    }

    int Front() {
        if (currcnt == 0)
            return -1;
        return front->data;
    }

    int Rear() {
        if (currcnt == 0)
            return -1;
        return back->data;
    }

    bool isEmpty() { return currcnt == 0; }

    bool isFull() { return currcnt == size; }
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