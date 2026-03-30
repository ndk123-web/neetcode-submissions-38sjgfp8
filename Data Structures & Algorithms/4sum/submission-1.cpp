class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int left , right , n = nums.size();

        sort(nums.begin(),nums.end());

        if (nums.size() < 4) {
            return res;
        }

        for (int i = 0 ; i < n - 3; i++) {

            if (i > 0 && nums[i-1] == nums[i]) continue;

            for (int j = i + 1 ; j < n - 2 ; j++) {
                
                if (j > i + 1 && nums[j-1] == nums[j]) continue;

                left = j + 1;
                right = n - 1;

                while (left < right) {
                    long long  sum = (long long)nums[left] + nums[right] + nums[i] + nums[j];
                    if (sum < target) {
                        left++;
                    }
                    else if (sum > target) {
                        right--;
                    }
                    else {
                        res.push_back({nums[i],nums[j],nums[left],nums[right]});
                        left++;
                        right--;

                        while (left < right && nums[left] == nums[left-1]) left++;
                        while (left < right && nums[right] == nums[right+1]) right--;
                    }
                }
            }
        }

        return res;

    }
};