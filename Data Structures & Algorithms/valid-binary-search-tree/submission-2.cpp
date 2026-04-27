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
    bool rec(TreeNode* root, int mn, int mx) {
        if (root == NULL) {
            return true;
        }

        if (mn >= root->val || mx <= root->val) {
            return false;
        }

        bool l = rec(root->left, mn, root->val);
        bool r = rec(root->right, root->val, mx);

        return (l && r);
    }

    bool isValidBST(TreeNode* root) {
        bool ans = rec(root, INT_MIN, INT_MAX);
        return ans;
    }
};
