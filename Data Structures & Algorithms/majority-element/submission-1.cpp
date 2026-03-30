class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int trackElement , count = 0 , n = nums.size();

        for (int i = 0 ; i < n ; i++) {
            if (nums[i] == trackElement) {
                count++;
            }
            else if (nums[i] != trackElement && count != 0) {
                count--;
            }else {
                trackElement = nums[i];
                count++;
            }
        }

        return trackElement;      
    }
};