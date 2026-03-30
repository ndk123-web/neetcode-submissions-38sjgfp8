class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int r = lower_bound(arr.begin(),arr.end(),x) - arr.begin();
        int l = r - 1;
        vector<int> res;

        while (k--) {
            if (l < 0) {
                res.push_back(arr[r++]);
            }
            else if (r >= n) {
                res.push_back(arr[l--]);
            }
            else if (abs(arr[l] - x) <= abs(arr[r] - x)) {
                res.push_back(arr[l--]);
            }
            else {
                res.push_back(arr[r++]);
            }
        }

        sort(res.begin(),res.end());
        return res;
    }
};