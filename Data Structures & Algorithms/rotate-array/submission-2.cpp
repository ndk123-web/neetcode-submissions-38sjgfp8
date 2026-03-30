class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int normalize_k = k % n;

        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin() + normalize_k);
        reverse(nums.begin()+normalize_k,nums.end());

    }
};