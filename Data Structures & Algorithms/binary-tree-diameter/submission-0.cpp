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
    int rec(TreeNode* root, int& ans) {
        if (root == NULL) {
            return 0;
        }
        int lh = rec(root->left, ans);
        int rh = rec(root->right, ans);
        ans = max(ans, lh + rh + 1);
        return max(lh, rh) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        rec(root, ans);
        return ans - 1;
    }
};
