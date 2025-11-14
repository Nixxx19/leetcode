class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0, head);
        ListNode* current = &dummy;
        while (current->next && current->next->next) {
            if (current->next->val == current->next->next->val) {
                current->next->next = current->next->next->next;
            } else {
                current = current->next;
            }
        }
        return dummy.next;
    }
};
