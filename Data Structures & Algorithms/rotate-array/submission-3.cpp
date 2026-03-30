class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int normalize_k = k % n;

        this->reveresBro(0 , n , nums);
        this->reveresBro(0 , normalize_k , nums);
        this->reveresBro(normalize_k , n , nums);

    }
    void reveresBro(int left , int right, vector<int>& nums) {
        while (left < right) {
            swap(nums[left],nums[right]);
            left++; right--;
        }
    }
};