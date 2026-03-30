class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int left = 0;
        int right = 0;

        if (s2.size() < s1.size()) return false;
        sort(s1.begin(),s1.end());
        
        while (left <= s2.size() - s1.size()) {
            string part = s2.substr(left,s1.size());
            sort(part.begin(),part.end());
            if (part == s1) return true; 
            left++;
        }

        return false;
    }
};
