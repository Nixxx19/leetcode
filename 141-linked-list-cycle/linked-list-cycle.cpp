class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> s;
        while (head) {
            if (s.count(head)) return true;
            s.insert(head);
            head = head->next;
        }
        return false;
    }
};
