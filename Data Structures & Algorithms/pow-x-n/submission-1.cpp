class Solution {
public:
    double helper(double x, int n) {
        if (n == 0)
            return 1;

        double half = helper(x, (n / 2));
        return (n % 2 == 0) ? half * half : x * half * half;
    }

    double myPow(double x, int n) {
        double res = helper(x, n);
        return (n < 0) ? 1 / res : res;
    }
};