class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int missing = 1;

        for (int i = 1; i < 100000000 ; i++) {
            bool found = false;
            for (auto& num : nums) {
                if (num == i) {
                    found = true; 
                    break;
                }
            }
            if (!found) {
                return i;
            }
        }
        
        return missing;
    }
};