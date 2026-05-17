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
    ListNode* merge(ListNode* h1, ListNode* h2) {
        ListNode dummy;
        ListNode* node = &dummy;
        while (h1 != nullptr && h2 != nullptr) {
            if (h1->val <= h2->val) {
                node->next = h1;
                h1 = h1->next;
                node = node->next;
            }
            else {
                node->next = h2;
                h2 = h2->next;
                node = node->next;
            }
        }
        if (h1 != nullptr) node->next = h1;
        if (h2 != nullptr) node->next = h2;
        return dummy.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0 || lists[0] == nullptr) return nullptr;
        if (n == 1) return lists[0];

        ListNode* head = lists[0];
        for (int i = 1; i < n; i++) {
            head = merge(head, lists[i]);
        }

        return head;
    }
};
