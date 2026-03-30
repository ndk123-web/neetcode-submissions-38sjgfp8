class Solution {
public:

    vector<int> mergeLR(vector<int>& left, vector<int>& right) {
        vector<int> normalized;
        int i = 0 , j = 0;

        while (i < left.size() && j < right.size()) {
            if (left[i] < right[j]) {
                normalized.push_back(left[i++]);
            }else {
                normalized.push_back(right[j++]);
            }
        }

        while (i < left.size()) {
            normalized.push_back(left[i++]);
        }

        while (j < right.size()) {
            normalized.push_back(right[j++]);
        }

        return normalized;
    }

    vector<int> divide(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums;
        }
        int mid = nums.size() / 2;
        vector<int> L(nums.begin(),nums.begin()+mid);
        vector<int> R(nums.begin()+mid,nums.end());

        L = divide(L);
        R = divide(R);

        vector<int> merge = mergeLR(L,R);
        
        return merge;
    }

    vector<int> sortArray(vector<int>& nums) {
        return divide(nums);
    }
};