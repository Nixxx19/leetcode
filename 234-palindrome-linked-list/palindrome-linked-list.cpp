class Solution {
public:
    ListNode* front;
    bool isPalindrome(ListNode* head) {
        front = head;
        return dfs(head);
    }
    bool dfs(ListNode* node) {
        if (!node) return true;
        if (!dfs(node->next)) return false;
        if (front->val != node->val) return false;
        front = front->next;
        return true;
    }
};
