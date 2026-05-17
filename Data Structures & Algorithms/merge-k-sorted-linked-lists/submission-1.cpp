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
        if (lists.size() == 0) return nullptr;

        while (lists.size() > 1) {
            vector<ListNode*> mergedLists;
            for (int i = 0; i < lists.size(); i+=2) {
                ListNode* l1 = lists[i];
                ListNode* l2 = (i + 1 < lists.size() ? lists[i + 1] : nullptr);
                ListNode* merged = merge(l1, l2);
                mergedLists.push_back(merged);
            }
            lists = mergedLists;
        }
        return lists[0];
    }
};
