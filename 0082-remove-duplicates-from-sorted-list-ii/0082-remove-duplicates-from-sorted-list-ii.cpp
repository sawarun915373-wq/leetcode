class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0, head);
        ListNode* prev = &dummy;

        while (prev->next) {
            ListNode* cur = prev->next;

            if (cur->next && cur->val == cur->next->val) {
                int dup = cur->val;
                while (cur && cur->val == dup) cur = cur->next;
                prev->next = cur;
            } else {
                prev = prev->next;
            }
        }
        return dummy.next;
    }
};