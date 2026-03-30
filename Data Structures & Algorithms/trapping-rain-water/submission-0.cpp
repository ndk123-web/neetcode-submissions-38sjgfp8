class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n - 1;

        if (height.empty()) return 0;

        int leftMax = height[left];
        int rightMax = height[right];
        int res = 0;

        while (left < right) {
            if (leftMax < rightMax) {
                left++;
                leftMax = max(leftMax,height[left]);
                res = res + leftMax - height[left];
            }else {
                right--;
                rightMax = max(rightMax,height[right]);
                res = res + rightMax - height[right];
            }
        }

        return res;
    }
};
