class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int> mapp;

        for (int& bill : bills) {
            if (bill == 5) {
                mapp[5]++;
                continue;
            }

            if (bill == 10 && mapp[5] >= 1) {
                mapp[5]--;
                mapp[10]++;
                continue;
            }

            // check 20 is there
            if (mapp[10] >= 1 && mapp[5] >= 1) {
                mapp[10]--;
                mapp[5]--;
                continue;
            }
            else if (mapp[5] >= 3) {
                mapp[5] = mapp[5] - 3;
            }
            else {
                return false;
            }
        }

        return true;      
    }
};