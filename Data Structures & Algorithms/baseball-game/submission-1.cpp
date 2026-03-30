class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int res = 0;

        for (auto& s : operations) {
            if (s == "+") {
                int f = st.top(); st.pop();
                int s = st.top();
                st.push(f);
                st.push(f+s);
                res = res + (f+s);
            }
            else if (s == "C") {
                int top = st.top(); 
                st.pop();
                res = res - top;
            }
            else if (s == "D") {
                int top = st.top();
                res = res + (top*2);
                st.push(top*2);
            }
            else {
                res = res + stoi(s);
                st.push(stoi(s));
            }
        }

        return res;
    }
};