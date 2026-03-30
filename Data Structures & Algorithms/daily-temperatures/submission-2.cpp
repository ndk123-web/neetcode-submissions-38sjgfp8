class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n,0);
        int k = 0;

        for (int i = 0 ; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] < nums[j]) {
                    res[k] = j - i;
                    break;
                }
            }
            k++;
        }

        return res;
    }
};
