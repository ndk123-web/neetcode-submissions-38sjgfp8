class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        double res;
        nums1.insert(nums1.end(),make_move_iterator(nums2.begin()),make_move_iterator(nums2.end()));

        sort(nums1.begin(),nums1.end());

        if (nums1.size() % 2 == 0) {
            int mid = nums1.size()/2;
            res = (double)(nums1[mid] + nums1[mid-1]) / 2 ; 
        }
        else {
            res = (double) nums1[nums1.size()/2];
        }

        return res;
    }
};
