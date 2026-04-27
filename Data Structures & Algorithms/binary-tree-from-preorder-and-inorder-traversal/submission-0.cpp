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
    TreeNode* rec(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie, unordered_map<int, int>& mp) {
        if (ps > pe || is > ie) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[ps]);
        int ii = mp[preorder[ps]];
        int len = ii - is;

        root->left = rec(preorder, inorder, ps + 1, ps + len, is, ii - 1, mp);
        root->right = rec(preorder, inorder, ps + len + 1, pe, ii + 1, ie, mp);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }

        TreeNode* root = rec(preorder, inorder, 0, n - 1, 0, n - 1, mp);
        return root;
    }
};
