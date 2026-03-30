class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int left , right , n = nums.size();

        sort(nums.begin(),nums.end());

        for (int i = 0 ; i < n - 2; i++) {
            left = i + 1 , right = n - 1;

            if (i > 0 && nums[i-1] == nums[i]) continue;

            while (left < right) {
                int sum = nums[left] + nums[right] + nums[i];

                if (sum < 0) {
                    left++;
                }else if (sum > 0) {
                    right--;
                }else {
                    res.push_back({nums[left],nums[right],nums[i]});
                    left++;
                    right--;

                    while (left < right && nums[left] == nums[left-1]) left++;
                    while (left < right && nums[right] == nums[right+1]) right--;
                }
            }
        }

        return res;
    }
};
