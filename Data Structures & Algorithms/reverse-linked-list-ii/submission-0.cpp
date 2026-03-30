class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode* beforeLeft = &dummy;

        // 1. reach node before left
        for (int i = 1; i < left; i++) {
            beforeLeft = beforeLeft->next;
        }

        // 2. reverse sublist
        ListNode* curr = beforeLeft->next;
        ListNode* prev = nullptr;

        for (int i = 0; i <= right - left; i++) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // 3. reconnect
        beforeLeft->next->next = curr; // left node → afterRight
        beforeLeft->next = prev;       // beforeLeft → right node

        return dummy.next;
    }
};
