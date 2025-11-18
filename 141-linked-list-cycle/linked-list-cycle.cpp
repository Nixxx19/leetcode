class Solution {
public:
    bool hasCycle(ListNode *head) {
        while (head) {
            if (head->val == 1e9+7) return true;
            head->val = 1e9+7;
            head = head->next;
        }
        return false;
    }
};
