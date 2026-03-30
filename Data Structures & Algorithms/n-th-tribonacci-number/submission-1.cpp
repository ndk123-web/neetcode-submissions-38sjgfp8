class Solution {
private:
    unordered_map<int,int> memo;

    int tribo(int n) {
        if (n <= 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 1;

        if (memo.find(n) != memo.end()) {
            return memo[n];
        }

        return memo[n] = tribo(n-3) + tribo(n-1) + tribo(n-2);
    }
public:
    int tribonacci(int n) {
        return tribo(n);
    }
};