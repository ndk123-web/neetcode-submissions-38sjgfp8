class Solution {
private:
    unordered_map<int,string> phoneMap = {
        {2, "ABC"},
        {3, "DEF"},
        {4, "GHI"},
        {5, "JKL"},
        {6, "MNO"},
        {7, "PQRS"},
        {8, "TUV"},
        {9, "WXYZ"},
    };

    vector<string> res;
    string oneres;

    void combiner(string& digits, int idx) {
        if (idx == digits.size()) {
            res.push_back(oneres);
            return;
        }

        int currNum = digits[idx] - '0';
        string currDigit = phoneMap[currNum];
        
        for (int i = 0 ; i < currDigit.size(); i++) {
            oneres.push_back(tolower(currDigit[i]));
            combiner(digits,idx+1);
            oneres.pop_back();
        }

        return;
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return res;

        combiner(digits,0);
        return res;
    }
};
