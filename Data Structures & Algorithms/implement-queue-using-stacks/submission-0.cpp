class MyQueue {
private:
    stack<int> st;
public:
    MyQueue() {}
    
    void push(int x) {
        this->st.push(x);
    }
    
    int pop() {
        stack<int> temp;

        while (!this->st.empty()) {
            temp.push(this->st.top()); this->st.pop();
        }   

        int pop = temp.top();
        temp.pop();

        while (!temp.empty()) {
            this->st.push(temp.top()); temp.pop();
        }

        return pop;
    }
    
    int peek() {
        stack<int> temp;

        while (!this->st.empty()) {
            temp.push(this->st.top());  this->st.pop();
        }

        int peek = temp.top();

        while (!temp.empty()) {
            this->st.push(temp.top()); temp.pop();
        }

        return peek;
    }
    
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */