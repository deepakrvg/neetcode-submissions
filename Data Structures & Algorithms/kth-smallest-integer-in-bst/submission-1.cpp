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
    int rec(TreeNode* root, int k, int& count) {
        if (root == NULL) {
            return -1;
        }

        int l = rec(root->left, k, count);
        if (l != -1) return l;
        count++;
        if (count == k) {
            return root->val;
        }
        int r = rec(root->right, k, count);
        return r;
    }

    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int ans = rec(root, k, count);
        return ans;
    }
};
