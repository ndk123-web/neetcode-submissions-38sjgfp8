class Solution {
private:
    int res;

public:
    int findJudge(int n, vector<vector<int>>& trust) {
        res = 1;

        vector<int> nums(n,0);    

        for (int i = 0 ; i < trust.size(); i++) {
            nums[trust[i][1]-1]++;
        }
        
        int maxIdx = 0;
        int maxNumber = INT_MIN;

        for (int i = 0 ; i < nums.size(); i++) {
            if (maxNumber < nums[i]) {
                maxNumber = nums[i];
                maxIdx = i;
            }
        }

        for (int i = 0 ; i < nums.size(); i++) {
            if (maxIdx == i) continue;
            if (nums[i] != 0){
                res = -1;
                break;
            } 
        }

        if (res != -1) 
            res = maxIdx + 1;

        return res;
    }
};