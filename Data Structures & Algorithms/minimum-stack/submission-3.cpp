class MinStack {
private: 
    stack<int> st;
    stack<int> mn;
public:
    MinStack() {}
    
    void push(int val) {
        st.push(val);
        if (mn.empty() || mn.top() >= val) mn.push(val);
    }
    
    void pop() {
        if (st.top() == mn.top()) mn.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mn.top();
    }
};
