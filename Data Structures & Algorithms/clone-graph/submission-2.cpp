/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) {
            return NULL;
        }
        Node* root = new Node(node->val);
        unordered_map<Node*, Node*> mp;
        queue<Node*> q;
        q.push(node);
        mp[node] = root;
        // vis[node->val] = 1;
        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();
            // vis[temp->val] = 1;
            for (auto x : temp->neighbors) {
                if (mp.find(x) == mp.end()) {
                    mp[x] = new Node(x->val);
                    q.push(x);
                }
                mp[temp]->neighbors.push_back(mp[x]);
            }
        }
        return root;
    }
};
