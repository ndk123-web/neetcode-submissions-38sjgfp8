class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> mapp(wordList.begin(),wordList.end());
        queue<string> q;
        q.push(beginWord);
        int steps= 1;

        while (!q.empty()) {

            int size = q.size();

            for (int i = 0 ; i < size; i++) {
                string curr = q.front();
                q.pop();

                if (curr==endWord) {
                    return steps;
                }

                for (int j = 0 ; j < curr.size(); j++) {
                    string t = curr;

                    for (char ch = 'a' ; ch <= 'z'; ch++) {
                        t[j] = ch;
                        if (mapp.find(t) != mapp.end()) {
                            q.push(t);
                            mapp.erase(t);
                        }
                    }
                }
            }

            steps++;
        }

        return 0;
    }
};
