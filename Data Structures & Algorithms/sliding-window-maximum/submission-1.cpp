class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int n = nums.size();
        
        for (int i = 0; i <= n - k ; i++) {
            int currentMax = INT_MIN;
            for (int j = i; j <= i + k - 1; j++) {
                currentMax = max(currentMax,nums[j]);
            }
            res.push_back(currentMax);
        }

        return res;
    }
};
