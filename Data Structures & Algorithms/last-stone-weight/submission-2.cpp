class Solution {
private:
    priority_queue<int> pq;

public:
    int lastStoneWeight(vector<int>& stones) {
        for (int& num : stones) {
            pq.push(num);
        }

        while (pq.size() != 1) {
            int ft = pq.top(); pq.pop();

            if (pq.size() == 1 && pq.top() == ft) return 0;
            int st = pq.top(); pq.pop();

            if (ft != st) 
                pq.push(ft-st);
        }   

        return pq.top(); 
    }
};
