class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int curr = 0;
        int n = s.size();

        while (curr < n) {

            int st = curr + minJump;
            int end = curr + maxJump;

            if (st > end) {
                return false;
            }

            if (end == n - 1) {
                return s[n-1] == '0' ? true : false;
            }

            bool found = false;
            for (int i = st; i <= end; i++){
                if (s[i] == '0') {
                    int nst = i + minJump;
                    int nend = min(i + maxJump, n - 1);
                    if (nend == n - 1 && nst <= nend && s[nend] == '0') {
                        return true;
                    }
                    found = true;
                    curr = i;
                }
            }

            if (!found) {
                return false;
            }
        }   

        return false;   
    }
};