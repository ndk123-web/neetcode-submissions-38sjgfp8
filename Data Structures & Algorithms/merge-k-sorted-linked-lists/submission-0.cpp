/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
private:
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode dummy(0);
        ListNode* curr = &dummy;

        while (a && b) {
            if (a->val <= b->val) {
                curr->next = a;
                a=a->next;
            }else {
                curr->next = b;
                b=b->next;
            }
            curr=curr->next;
        }

        curr->next = a ? a : b;
        return dummy.next;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        ListNode* res = lists[0];
        for (int i=1 ; i < lists.size(); i++) {
            res = merge(res,lists[i]);
        }    

        return res;
    }
};
