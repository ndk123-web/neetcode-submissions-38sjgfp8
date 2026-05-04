class Solution {
public:
    long long minEnd(int n, int x) {

        /*
            n = 3 , x = 2

            res = 2
            i. res = res + 1 | x
                   = 3 | 2 => 0 1 1 | 0 1 0 => 0 1 1 => 3
            
            ii. res = res + 1 | x
                   = 4 | 2 => 1 0 0 | 0 1 0 => 1 1 0 (6)
        */

        long long res = x;
        for (int i = 0; i < n - 1; i++) {
            res = (res + 1) | x;
        }
        return res;
    }
};