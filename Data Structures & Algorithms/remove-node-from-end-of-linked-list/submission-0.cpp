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
        ListNode* prev;
        ListNode* node = head;
        while (n--) {
            node = node->next;
            // prev = node;
        }

        ListNode* curr = head;
        while (node != nullptr) {
            prev = curr;
            node = node->next;
            curr = curr->next;
        }
        if (curr == head) return head->next;
        prev->next = curr->next;
        delete node;
        return head;
    }
};
