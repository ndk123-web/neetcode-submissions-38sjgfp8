class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int num = nums[i];

            if (tails.empty()) {
                tails.push_back(num);
            }
            else {
                auto it = lower_bound(tails.begin(),tails.end(),num);

                // it means we didn't find any number >= target
                if (it == tails.end()) {
                    // then append it num
                    tails.push_back(num);
                }
                
                // it means present so we need to replace that
                else {
                    int index = it - tails.begin();
                    tails[index] = num;
                }
            }
        }

        return tails.size();        
    }
};
