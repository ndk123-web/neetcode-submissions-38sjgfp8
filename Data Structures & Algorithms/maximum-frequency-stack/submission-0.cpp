class FreqStack {
private:
    vector<int> stack;
    unordered_map<int,int> mapp;
public:
    FreqStack() {}
    
    void push(int val) {
        stack.push_back(val);
        mapp[val]++;
    }
    
    int pop() {
        int mxCnt = 0;
        for (auto& [_, freq] : mapp) {
            mxCnt = max(mxCnt,freq);
        }
        int i = stack.size() - 1;

        while (mapp[stack[i]] != mxCnt) {
            i--;
        }

        int val = stack[i];
        
        stack.erase(stack.begin() + i);
        mapp[val]--;

        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */