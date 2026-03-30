class MinStack {
private:
    stack<int> st;
public:
    MinStack() {}
    
    void push(int val) {
        st.push(val);
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        stack<int> temp;
        temp = st;

        int small = INT_MAX;
        while (!temp.empty()) {
            small = min(small,temp.top());
            temp.pop();
        }

        return small;
    }
};
