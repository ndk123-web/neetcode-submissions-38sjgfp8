class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int res = 0;

        int leftMax = height[left] , rightMax = height[right];
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
