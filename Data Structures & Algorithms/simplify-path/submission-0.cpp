class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        string word; 

        for (auto& c : path + "/") {
            if (c == '/') {
               if (word == "..") {
                if (!stack.empty()) stack.pop_back();
               }
               else if (!word.empty() && word != ".") stack.push_back(word);
                word.clear();
            }
            else {
                word = word + c;
            }
        }

        string res;
        res = stack.empty() ? "/" : "";
        for (int i = 0 ; i < stack.size(); i++) {
            res = res + "/" + stack[i];
        }

        return res;
    }
};