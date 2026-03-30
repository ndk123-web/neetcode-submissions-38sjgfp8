class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int n = nums.size();
        vector<int> res(n-k+1);
        int left = 0 , right = 0;

        while (right < n) {
            while (!dq.empty() && nums[dq.back()] < nums[right]) {
                dq.pop_back();
            }

            dq.push_back(right);

            if (left > dq.front()) {
                dq.pop_front();
            }
            
            if ((right + 1) >= k) {
                res[left] = nums[dq.front()];
                left++;
            }

            right++;
        }

        return res;  
    }
};
