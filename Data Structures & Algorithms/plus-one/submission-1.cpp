class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        long long n = digits.size();

        long long total = 0;
        for (long long i = 0; i < n; i++) {
            total = (total * 10) + digits[i];
        }   
        total = total + 1;

        while (total > 0) {
            long long rem = total % 10;
            total = total / 10;
            result.push_back(rem);
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
