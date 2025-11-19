class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        ListNode *a = headA, *b = headB;
        while (a) lenA++, a = a->next;
        while (b) lenB++, b = b->next;
        a = headA; 
        b = headB;
        if (lenA > lenB) {
            int d = lenA - lenB;
            while (d--) a = a->next;
        } else {
            int d = lenB - lenA;
            while (d--) b = b->next;
        }
        while (a && b && a != b) {
            a = a->next;
            b = b->next;
        }
        return a;
    }
};
