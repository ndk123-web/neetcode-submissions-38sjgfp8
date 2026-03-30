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
private:
    unordered_map<Node*,Node*> mapp;

    Node* dfs(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }

        if (mapp.count(node)) {
            return mapp[node];
        }

        Node* copy = new Node(node->val);
        mapp[node] = copy;

        for (Node* nei : node->neighbors) {
            copy->neighbors.push_back(dfs(nei));
        }

        return copy;
    }

public:
    Node* cloneGraph(Node* node) {
        return dfs(node);      
    }
};
