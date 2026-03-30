class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int next = 1;
        int prev = 0;

        if (nums.size() == 1) return 1;

        while (next < nums.size()) {
            if (nums[next] == nums[prev]) {
                nums[prev] = -101;
            }
            next++;
            prev++;
        }

        vector<int> temp;
        for (int i = 0 ; i < nums.size(); i++) {
            if (nums[i] != -101) {
                temp.push_back(nums[i]);
            }
        }

        nums = (temp);
        return temp.size();
    }
};