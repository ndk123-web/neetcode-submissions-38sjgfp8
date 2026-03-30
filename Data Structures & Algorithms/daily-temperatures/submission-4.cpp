class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        stack<pair<int,int>> data;
        int n = nums.size();
        vector<int> res(n,0);

        // val , idx
        for (int i = 0 ; i < n; i++) {
            while (!data.empty() && data.top().first < nums[i]) {
                res[data.top().second] = i - data.top().second ;
                data.pop();
            }
            
            data.push({nums[i],i});
            // else {
            // data.push_back({nums[i],i});
            // }
        }

        return res;
    }
};
