class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int c = 0, m=0;
        for(int& n: nums){
            if (c==0){
                c = n;
                m=max(c,m);
                continue;
            }
            if (c < 0){
                c = n;
                m=max(m,c);
                continue;
            }
            c+= n;
            m= max(m,c);
        }

        return c < 0 ? -1 : m;
    }
};
