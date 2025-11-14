class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        head->next = deleteDuplicates(head->next);
        if (head->val == head->next->val) head = head->next;
        return head;
    }
};
