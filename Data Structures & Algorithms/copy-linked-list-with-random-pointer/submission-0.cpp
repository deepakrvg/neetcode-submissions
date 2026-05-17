/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        // Node* h = new (head->val);
        Node* node = head;
        while (node != nullptr) {
            Node* nxt = node->next;
            Node* nnode = new Node(node->val);
            node->next = nnode;
            nnode->next = nxt;
            node = nxt;
        }

        node = head;
        while (node != nullptr && node->next != nullptr) {
            if (node->random == nullptr) node->next->random = nullptr;
            else node->next->random = node->random->next;
            node = node->next->next;
        }

        Node* h = head->next;
        node = h;
        Node* n = head;
        while (n != nullptr) {
            Node* on = n->next->next;
            n->next = on;
            if (on != nullptr) {
                Node* nn = on->next;
                node->next = nn;
            }
            node = node->next;
            n = on;
        }
        return h;
    }
};
