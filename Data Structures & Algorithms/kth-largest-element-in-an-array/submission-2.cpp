class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),[](auto& a, auto& b){return a > b;});
        return nums[k-1];
    }
};
