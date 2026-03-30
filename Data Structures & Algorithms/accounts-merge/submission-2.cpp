class Solution {
private:
    
    // neet@gmail.com -> neet@gmail.com
    // neet_dsa@gmail.com -> neet_dsa@gmail.com
    unordered_map<string,string> parents;

    // neet@gmail.com -> neet
    // neet_dsa@gmail.com -> neet
    unordered_map<string,string> owners;
    unordered_map<string, vector<string>> groups;

    vector<vector<string>> res;

    string find(string s) {
        if (parents[s] == s)
            return s;
        return find(parents[s]);  // path compression
    }

    void unionAccount(vector<string>& account) {
        string parent = account[0];
        string baseEmail = account[1];

        for (int i = 2; i < account.size(); i++) {
            string parentOfBaseEmail = find(baseEmail);
            string parentOfNextEmail = find(account[i]);

            if (parentOfBaseEmail != parentOfNextEmail) {
                parents[parentOfNextEmail] = parentOfBaseEmail;
            }
        }

        return;
    }

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        // 1. Build parents and owners table
        // parents => (email) -> (email)
        // owners => (email) -> name 
        for (vector<string>& acc : accounts) {
            int i = 1;
            string parent = acc[0];

            for (int j = i ; j < acc.size(); j++) {
                parents[acc[j]] = acc[j];
                owners[acc[j]] = parent;
            }
        }

        // 2. Union Account Emails 
        for (vector<string>& acc : accounts) {
            unionAccount(acc);
        }    

        for (auto& p : parents) {
            string email = p.first;
            string root = find(email);
            groups[root].push_back(email);
        }

        for (auto& g : groups) {
            vector<string> emails = g.second;
            sort(emails.begin(),emails.end());

            string owner = owners[g.first];
            emails.insert(emails.begin(),owner);

            res.push_back(emails);
        }

        return res;
    }
};