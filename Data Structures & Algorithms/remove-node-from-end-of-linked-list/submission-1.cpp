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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy;
        dummy.next = head;
        ListNode* slow = &dummy;
        ListNode* fast = head;
        while (n-- && fast != nullptr) {
            fast = fast->next;
        }

        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* target = slow->next;
        slow->next = target->next;
        delete target;
        return dummy.next;
    }
};
