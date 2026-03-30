class Solution {
public:
    string decodeString(string s) {
        string cur;
        vector<string> chars;
        vector<int> ints;
        int k = 0;
        string res;

        for (auto& c : s) {
            if (isdigit(c)) {
                k = k * 10 + (c-'0');
            }
            else if (c == '[') {
                chars.push_back(cur);
                ints.push_back(k);
                k = 0;
                cur = "";
            }
            else if (c == ']') {
                string temp = cur;
                cur = chars.back();
                int count = ints.back();
                ints.pop_back();
                chars.pop_back();
                for (int i = 0 ; i < count; i++) {
                    cur = cur + temp;
                }
            }else {
                cur = cur + c;
            }
        }

        return cur;
    }
};