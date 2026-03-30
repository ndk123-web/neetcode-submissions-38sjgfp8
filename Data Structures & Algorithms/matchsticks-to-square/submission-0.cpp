class Solution {
private:
    bool dfs(vector<int>& nums,int t, int b,int l,int r,int idx, int target) {
        if (l > target / 4 || r > target / 4 || t > target / 4 || b > target / 4) 
            return false;
        if (l == r && t == b && l == t && idx == nums.size()) 
            return true;

        bool res = dfs(nums,t+nums[idx],b,l,r,idx+1,target) || 
                   dfs(nums,t,b+nums[idx],l,r,idx+1,target) || 
                   dfs(nums,t,b,l+nums[idx],r,idx+1,target) || 
                   dfs(nums,t,b,l,r+nums[idx],idx+1,target);
        
        return res;
    }

public:
    bool makesquare(vector<int>& matchsticks) {
        int target = accumulate(matchsticks.begin(),matchsticks.end(),0);
        return dfs(matchsticks,0,0,0,0,0,target);      
    }
};