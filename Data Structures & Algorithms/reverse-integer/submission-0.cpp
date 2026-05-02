class Solution {
   public:
    int reverse(int x) {
        int sign = (x > 0) ? 1 : -1;
        int res = 0;

        x = abs(x);
        while (x > 0) {
            int digit = x % 10;
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && digit > 7)) return 0;
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && digit < -8)) return 0;
            res = (res * 10) + digit;
            x = x / 10;
        }

        res = sign * res;

        return res;
    }
};
