class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> hashSet;
        int left = 0;

        for (int right = 0 ; right < n ; right++) {
            if (right-left > k){
                hashSet.erase(nums[left]);
                left++;
            } 
            if (hashSet.find(nums[right]) != hashSet.end()) {
                return true;
            }
            hashSet.insert(nums[right]);
        }   

        return false;
    }
};