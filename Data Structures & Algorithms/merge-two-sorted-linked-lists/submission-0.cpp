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
public:
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (!list1) return list2;
    if (!list2) return list1;

    ListNode* newHead = nullptr;
    ListNode* curr = nullptr;

    while (list1 && list2) {
        int val;
        if (list1->val <= list2->val) {
            val = list1->val;
            list1 = list1->next;
        } else {
            val = list2->val;
            list2 = list2->next;
        }

        if (!newHead) {
            newHead = new ListNode(val);
            curr = newHead;
        } else {
            curr->next = new ListNode(val);
            curr = curr->next;
        }
    }

    while (list1) {
        curr->next = new ListNode(list1->val);
        curr = curr->next;
        list1 = list1->next;
    }

    while (list2) {
        curr->next = new ListNode(list2->val);
        curr = curr->next;
        list2 = list2->next;
    }

    return newHead;
}

};
