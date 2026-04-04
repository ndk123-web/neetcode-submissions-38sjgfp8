class Solution {
public:
    int jump(vector<int>& nums) {
        int farthest = 0, currentEnd = 0, jump = 0;
        if (nums.size() == 1) return 0;

        for (int i = 0; i < nums.size(); i++) {

            farthest = max(farthest, i + nums[i]);

            if (currentEnd == i) {
                jump++;
                if (farthest >= nums.size() - 1 ) return jump;

                currentEnd = farthest;
            }
        }

        return jump;      
    }
};
