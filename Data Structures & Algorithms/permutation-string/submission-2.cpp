class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> hashMap;
        int s1n = s1.size();
        int s2n = s2.size();
        int left = 0 , right = s1n - 1;

        for (auto& s : s1) {
            hashMap[s]++;
        }

        while (right < s2n) {
            vector<int> count(26,0);
            bool isAllExist = true;

            for (int i = left ; i <= right; i++) {
                if (hashMap[s2[i]] == 0) {
                    isAllExist = false;
                    break;
                }
                count[s2[i] - 'a']++;
            }   
            
            if (isAllExist) {
                bool allValid = true;
                for (auto& p : hashMap) {
                    if (p.second != count[p.first - 'a']) {
                        allValid = false;
                        break;
                    }
                }
                if (allValid) return true;
            }
            left++;
            right++;
        }

        return false;
    }
};
