class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* new_head = nullptr;
        while (head) {
            ListNode* temp = head->next;
            head->next = new_head;
            new_head = head;
            head = temp;
        }
        return new_head;
    }
};
