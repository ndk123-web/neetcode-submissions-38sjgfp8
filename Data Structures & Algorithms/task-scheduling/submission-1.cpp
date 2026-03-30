class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26,0);
        priority_queue<int> heap;
        queue<pair<int, int>> q;

        for (char& task : tasks) {
            count[task - 'A']++;
        }

        for (int& cnt : count){
            if (cnt > 0)
                heap.push(cnt);
        }

        int time = 0;
        while (!heap.empty() || !q.empty()) {
            time++;

            if (!heap.empty()) {
                int cnt = heap.top() - 1;
                heap.pop();
                if (cnt > 0)
                    q.push({cnt, time + n});
            }

            if (!q.empty() && q.front().second == time) {
                heap.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};