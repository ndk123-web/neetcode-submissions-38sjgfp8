class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> sett;
        for (int& num: nums){
            if (sett.find(num) != sett.end()) 
                return true;
            
            sett.insert(num);
        }
        return false;
    }
};