class Solution {
public:
    string reorganizeString(string s) {
        string res ="";
        int n = s.size();

        vector<int> freq(26,0);
        for(char& c : s) freq[c-'a']++;

        // abbccdd
        // a:1 b:2 c:2 d:2

        priority_queue<pair<int,char>> pq;
        int idx=0;
        if(*max_element(freq.begin(),freq.end()) > (n+1)/2) {
            return "";
        }
        for(auto& f : freq) {
            if (f > 0) {
                pq.push({f,char(idx + 'a')});
            }
            idx++;
        }

        while (pq.size() >= 2){
            auto p = pq.top(); pq.pop();
            auto q = pq.top(); pq.pop();

            res=res+p.second;
            res=res+q.second;

            if(--p.first > 0) pq.push({p.first,p.second});
            if(--q.first > 0) pq.push({q.first,q.second});
        }

        if(!pq.empty()){
            if(pq.top().first > 1) {
                return "";
            }
            res=res+pq.top().second;
            // pq.pop();
        }

        return res;
    }
};