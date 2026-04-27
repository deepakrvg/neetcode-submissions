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
            return INT_MIN;
        }
        
        int ls = max(0, rec(root->left, ans));
        int rs = max(0, rec(root->right, ans));

        ans = max(ans, ls + rs + root->val);
        return max(ls, rs) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        rec(root, ans);
        return ans;
    }
};
