class MinStack {
private:
    stack<int> st;
    multiset<int> mset;
    int small;
public:
    MinStack() {}
    
    void push(int val) {
        st.push(val);
        mset.insert(val);
    }
    
    void pop() {
        mset.erase(mset.find(st.top()));
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return *mset.begin();
    }
};
