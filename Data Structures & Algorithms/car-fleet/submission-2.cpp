class Solution {
private:
    vector<double> st;
    vector<pair<int,int>> pr;
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        for (int i = 0 ; i < n ; i++){
            pr.push_back({position[i],speed[i]});
        }

        sort(pr.rbegin(),pr.rend());

        for (auto& p : pr) {
            st.push_back((double)(target-p.first)/p.second);
            if (st.size() >= 2 && st.back() <= st[st.size() - 2]) {
                st.pop_back();
            }
        }

        return st.size();
    }
};
