class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n <= 2) return 0;

        vector<int> maxLeft(n, 0);
        vector<int> maxRight(n, 0);

        // compute left max
        for (int i = 1; i < n; i++) {
            maxLeft[i] = max(maxLeft[i-1], height[i-1]);
        }

        // compute right max
        for (int i = n-2; i >= 0; i--) {
            maxRight[i] = max(maxRight[i+1], height[i+1]);
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            int waterHeight = min(maxLeft[i], maxRight[i]);
            if (waterHeight > height[i]) {
                res += waterHeight - height[i];
            }
        }

        return res;
    }
};
