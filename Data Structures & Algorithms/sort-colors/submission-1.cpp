class Solution {
public:
    void sortColors(vector<int>& nums) {
        int mx = *max_element(nums.begin(),nums.end());
        int mn = *min_element(nums.begin(),nums.end());

        int range = mx - mn + 1;

        vector<int> count(range,0);

        for (auto& num : nums) {
            count[num-mn]++;
        }

        int k = 0;
        for (int i = 0 ; i < count.size();i++) {
            if (count[i] != 0) {
                for (int j = 0 ; j < count[i]; j++) {
                    nums[k++] = i + mn;
                }
            }
        }
    }
};