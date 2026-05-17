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
        k--;
        while (node != nullptr && k > 0) {
            node = node->next;
            k--;
        }
        return node;
    }

    ListNode* reverse(ListNode* node) {
        ListNode* prevNode = nullptr;
        ListNode* nextNode = nullptr;
        while (node != nullptr) {
            nextNode = node->next;
            node->next = prevNode;
            prevNode = node;
            node = nextNode;
        }
        return prevNode;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = nullptr;
        while (temp != nullptr) {
            ListNode* kth = getKthNode(temp, k);
            if (kth == nullptr) {
                if (prevNode != nullptr) prevNode->next = temp;
                break;
            }

            ListNode* nextNode = kth->next;
            kth->next = nullptr;
            reverse(temp);
            if (temp == head) {
                head = kth;
            }
            else {
                prevNode->next = kth;
            }
            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};
