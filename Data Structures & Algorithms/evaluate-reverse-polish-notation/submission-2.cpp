class Solution {
private:
    stack<int> st;
public:

    void giveAns(string& op) {
        if (op == "+") {
            int f = st.top(); st.pop();
            int s = st.top(); st.pop();

            st.push(f+s);
        }   
        else if (op == "-") {
            int f = st.top(); st.pop();
            int s = st.top(); st.pop();

            st.push(s-f);
        }
        else if (op == "*") {
            int f = st.top(); st.pop();
            int s = st.top(); st.pop();

            st.push(f*s);
        }
        else if (op == "/") {
            int f = st.top(); st.pop();
            int s = st.top(); st.pop();

            st.push(s/f);   
        }
        else {
            st.push(stoi(op));
        }
    }

    int evalRPN(vector<string>& tokens) {

        for(auto& s : tokens) {
            giveAns(s);
        }   

        return st.top();
    }
};
