class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        // initially all childrens gets 1 candy as we know each child atleast have 1 minimum candy
        vector<int> leftPass(n, 1);
        vector<int> rightPass(n, 1);

        for (int i = 1; i < n; i++) {
            if (ratings[i-1] < ratings[i]) {
                leftPass[i] = leftPass[i-1] + 1;
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                rightPass[i] = rightPass[i+1] + 1;
            }
        }

        int s = 0;
        for (int i = 0; i < n; i++) {
            s = s + max(leftPass[i], rightPass[i]);
        }

        return s;
    }   
};