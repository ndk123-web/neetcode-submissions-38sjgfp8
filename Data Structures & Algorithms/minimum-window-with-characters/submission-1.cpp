class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> window , hashMapOfT;
        int left = 0;
        int st = 0 , end = INT_MAX;
        int smallest = INT_MAX;

        for (auto& c : t) {
            hashMapOfT[c]++;
        }

        int need = hashMapOfT.size() , have = 0;

        for (int right = 0 ; right < s.size(); right++) {
            window[s[right]]++;

            if (hashMapOfT.count(s[right]) && hashMapOfT[s[right]] == window[s[right]]) {
                have++;
            }

            while (have == need) {
                if (smallest > (right-left+1)) {
                    st = left;
                    end = right + 1;
                    smallest = (right-left+1);
                }

                window[s[left]]--;

                if (hashMapOfT.count(s[left]) && window[s[left]] < hashMapOfT[s[left]]) {
                    have--;
                }
                left++;
            }
        }

        return end == INT_MAX ? "" : s.substr(st,(end-st));
    }
};
