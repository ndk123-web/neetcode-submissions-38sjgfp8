class Solution {
public:
    bool isPalindrome(string s) {
        string newString = "";

        for (auto& c : s) {
            if(isalnum(c)) {
                newString+=tolower(c);
            }
        }

        return newString == string(newString.rbegin(),newString.rend());   
    }
};
