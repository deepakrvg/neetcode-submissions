/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* node = &dummy;
        int c = 0;
        while (l1 != nullptr && l2 != nullptr) {
            int val = l1->val + l2->val + c;
            c = val / 10;
            val = val % 10;
            node->next = new ListNode(val);
            l1 = l1->next;
            l2 = l2->next;
            node = node->next;
        }
        while (l1 != nullptr) {
            int val = l1->val + c;
            c = val / 10;
            val = val % 10;
            node->next = new ListNode(val);
            l1 = l1->next;
            node = node->next;
        }
        while (l2 != nullptr) {
            int val = l2->val + c;
            c = val / 10;
            val = val % 10;
            node->next = new ListNode(val);
            l2 = l2->next;
            node = node->next;
        }
        if (c) {
            node->next = new ListNode(c);
            node = node->next;
        }
        return dummy.next;
    }
};
