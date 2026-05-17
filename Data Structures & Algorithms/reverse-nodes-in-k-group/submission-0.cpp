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
    ListNode* getKthNode(ListNode* node, int k) {
        while (node != nullptr && k > 0) {
            node = node->next;
            k--;
        }
        return node;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy;
        dummy.next = head;

        ListNode* prevGroup = &dummy;
        while (true) {
            ListNode* kth = getKthNode(prevGroup, k);
            if (kth == nullptr) break;

            ListNode* nextGroup = kth->next;
            ListNode* prev = nextGroup;
            ListNode* curr = prevGroup->next;

            while (curr != nextGroup) {
                ListNode* newNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = newNode;
            }

            ListNode* tmp = prevGroup->next;
            prevGroup->next = kth;
            prevGroup = tmp;
        }
        return dummy.next;
    }
};
