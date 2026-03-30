/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) 
            return nullptr;
        
        unordered_map<Node*,Node*> mapp;
        queue<Node*> q;

        mapp[node] = new Node(node->val);
        q.push(node);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            for (Node* nei : curr->neighbors) {
                if (mapp.find(nei) == mapp.end()) {
                    mapp[nei] = new Node(nei->val);
                    q.push(nei);
                }
                mapp[curr]->neighbors.push_back(mapp[nei]);
            }
        }

        return mapp[node];
    }
};





