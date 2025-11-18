class Solution {
public:
    unordered_set<ListNode*> s;
    bool dfs(ListNode* node) {
        if (!node) return false;
        if (s.count(node)) return true;
        s.insert(node);
        return dfs(node->next);
    }
    bool hasCycle(ListNode *head) {
        return dfs(head);
    }
};
