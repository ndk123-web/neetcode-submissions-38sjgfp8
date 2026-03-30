class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> hashMap;
        int left = 0 , right = 1;
        hashMap[s[left]]++;
        int longest = 0 , maxVal = hashMap[s[left]];
        int n = s.size();

        while (right < n) {
            hashMap[s[right]]++;
            maxVal = max(hashMap[s[right]],maxVal);

            int sum = (right-left+1) - maxVal;
            if (sum > k) {
                hashMap[s[left]]--;
                left++;
            }
            longest = max(longest , (right - left + 1));
            right++;
        }

        return longest;
    }
};
