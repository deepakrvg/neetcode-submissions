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
    ListNode* reverse(ListNode* node) {
        if (node == nullptr) return node;
        ListNode* prev = nullptr;
        ListNode* nxt;
        while (node != nullptr) {
            nxt = node->next;
            node->next = prev;
            prev = node;
            node = nxt;
        }
        return prev;
    }

    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode dummy;
        ListNode* node = &dummy;
        while (a != nullptr && b != nullptr) {
            ListNode* an = a->next;
            ListNode* bn = b->next;

            node->next = a;
            node = node->next;
            node->next = b;
            node = node->next;
            a = an;
            b = bn;
        }

        if (a != nullptr) node->next = a;
        if (b != nullptr) node->next = b;
        return dummy.next;
    }

    void reorderList(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = reverse(slow->next);
        slow->next = nullptr;
        head = merge(head, mid);
    }
};
