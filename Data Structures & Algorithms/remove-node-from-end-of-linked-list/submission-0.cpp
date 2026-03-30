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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        int currlen = 0;
        ListNode* curr = head;
        while (curr) {
            curr=curr->next;
            len++; // 4 
        }

        curr = head;
        ListNode* prev = nullptr;
        while (curr) {
            if (len - currlen == n) {
                if (prev) {
                    prev->next = curr->next;
                } else {
                    head = curr->next;
                }
                break;
            }
            prev = curr;
            curr=curr->next;
            currlen++;
        }

        return head;
    }
};
