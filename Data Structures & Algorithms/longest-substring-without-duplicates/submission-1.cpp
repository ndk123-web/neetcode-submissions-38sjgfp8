class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_set<int> hashSet;
        int left = 0;
        int longest = 0;

        for (int right = 0; right < n; right++) {
            while (hashSet.count(s[right])) {
                hashSet.erase(s[left]);
                left++;
            }
            longest = max(longest , (right-left+1));
            hashSet.insert(s[right]);
        }

        return longest;
    }
};
