class Solution {
private:
    vector<vector<string>> res;
    vector<string> oneres;

    void part(string& s, int idx) {

        if (idx == s.size()) {
            res.push_back(oneres);
            return;
        }
        
        for (int i = idx; i < s.size(); i++) {
            string temp(s.begin()+idx , s.begin() + i + 1);
            if (!isPalindrome(temp))    
                continue;
            
            oneres.push_back(temp);
            part(s,i+1);
            oneres.pop_back();
        }

        return;
    }

    bool isPalindrome(string s) {
        int i = 0 , j = s.size() - 1;

        while (i < j) {
            if (s[i] != s[j])
                return false;
            
            i++;
            j--;
        }

        return true;
    }

public:
    vector<vector<string>> partition(string s) {
        part(s,0);
        return res; 
    }
};
