class Solution {
private:

    unordered_map<int,int> memo;

    int fibonacci(int n) {
        if (n <= 0) {
            return 1;
        }
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }

        if (memo.find(n) != memo.end()) {
            return memo[n];
        }

        memo[n] = fibonacci(n-1) + fibonacci(n-2);
        return memo[n];
    }

public:
    int climbStairs(int n) {
        return fibonacci(n);
    }
};
