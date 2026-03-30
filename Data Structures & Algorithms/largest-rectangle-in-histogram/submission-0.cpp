class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0 ; i < n ; i++) {
            int minVal = INT_MAX;
            for (int j = i; j < n ; j++) {
                if (i==j) {
                    maxArea = max(maxArea,heights[j]);
                    minVal = min(minVal,heights[j]);
                }
                else {
                    minVal = min(heights[j],minVal);
                    int currArea = (j-i+1) * minVal;
                    maxArea = max(maxArea,currArea);
                }
            }
        }

        return maxArea;   
    }
};
