class Solution:
    def isPalindrome(self, s: str) -> bool:
        ans = ''
        for i in range(len(s)):
            if s[i].isalpha() or s[i].isnumeric():
                ans+=s[i]

        return ans[::].lower() == ans[::-1].lower()
