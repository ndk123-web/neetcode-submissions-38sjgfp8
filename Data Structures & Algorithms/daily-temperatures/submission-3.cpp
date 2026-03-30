class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        vector<pair<int,int>> data;
        int n = nums.size();
        vector<int> res(n,0);

        // val , idx
        for (int i = 0 ; i < n; i++) {
            while (!data.empty() && data.back().first < nums[i]) {
                res[data.back().second] = i - data.back().second ;
                data.pop_back();
            }
            
            data.push_back({nums[i],i});
            // else {
            // data.push_back({nums[i],i});
            // }
        }

        return res;
    }
};
