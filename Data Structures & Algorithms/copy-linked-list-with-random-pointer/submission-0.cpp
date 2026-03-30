/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* curr = head;
        map<Node*,Node*> mapp;

        while (curr) {
            mapp[curr] = new Node(curr->val);
            curr=curr->next;
        }

        curr = head;
        while (curr) {
            Node* nNode = mapp[curr];
            nNode->next = mapp[curr->next];
            nNode->random = mapp[curr->random];

            curr= curr->next;
        }

        return mapp[head];
    }
};
