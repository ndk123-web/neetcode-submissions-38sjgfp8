class Solution {
private:

    int fibonacci(int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }

        return fibonacci(n-1) + fibonacci(n-2);
    }

public:
    int climbStairs(int n) {
        return fibonacci(n);
    }
};
