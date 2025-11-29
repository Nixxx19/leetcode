class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* res = nullptr;
        ListNode* tail = nullptr;

        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) { sum += l1->val; l1 = l1->next; }
            if (l2) { sum += l2->val; l2 = l2->next; }

            ListNode* node = new ListNode(sum % 10);
            if (!res) {
                res = node;
                tail = node;
            } else {
                tail->next = node;
                tail = node;
            }

            carry = sum / 10;
        }

        return res;
    }
};
