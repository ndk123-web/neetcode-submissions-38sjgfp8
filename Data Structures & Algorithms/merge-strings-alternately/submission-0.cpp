class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int ptrOfWord1 = 0;
        int ptrOfWord2 = 0;
        int sizeOfWord1 = word1.size();
        int sizeOfWord2 = word2.size();
        string res;

        bool flag = false;
        while ((ptrOfWord1 < sizeOfWord1) && (ptrOfWord2 < sizeOfWord2)) {
            if (!flag) 
                res += word1[ptrOfWord1++];
            else
                res += word2[ptrOfWord2++];
            flag = !flag;
        }

        while (ptrOfWord1 < sizeOfWord1) {
            res += word1[ptrOfWord1++];
        }

        while (ptrOfWord2 < sizeOfWord2) {
            res += word2[ptrOfWord2++];
        }

        return res;
    }
};