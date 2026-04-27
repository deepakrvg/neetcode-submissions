/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int rec(TreeNode* root, int mx) {
        if (root == NULL) {
            return 0;
        }

        mx = max(mx, root->val);

        int lm = rec(root->left, mx);
        int rm = rec(root->right, mx);
        if (mx == root->val) {
            return lm + rm + 1;
        }
        return lm + rm;
    }

    int goodNodes(TreeNode* root) {
        int mx = INT_MIN;
        int ans = rec(root, mx);
        return ans;
    }
};
