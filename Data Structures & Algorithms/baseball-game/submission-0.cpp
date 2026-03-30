class Solution {
public:
    int calPoints(vector<string>& operations) {
        int finalSum = 0;
        stack<int> st;
        int n = operations.size();

        for (int i = 0 ; i < n ; i++) {
            if (operations[i] == "+") {
                int f = st.top(); st.pop();
                int s = st.top(); 
                st.push(f);
                st.push(f+s);
            } 
            else if (operations[i] == "D") {
                int t = st.top();
                st.push(t*2);
            }
            else if (operations[i] == "C") {
                st.pop();
            }
            else {
                st.push(stoi(operations[i]));
            }
        }

        while (!st.empty()) {
            finalSum += st.top(); st.pop();
        }

        return finalSum; 
    }
};