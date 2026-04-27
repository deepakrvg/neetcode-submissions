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
    bool rec(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL && t2 == NULL) {
            return true;
        }
        else if (t1 == NULL || t2 == NULL) {
            return false;
        }

        if (t1->val != t2->val) {
            return false;
        }
        
        bool flag = true;
        flag = flag && rec(t1->left, t2->left);
        flag = flag && rec(t1->right, t2->right);
        return flag;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL) return false;
        bool ans = rec(root, subRoot);
        ans = ans || isSubtree(root->left, subRoot);
        ans = ans || isSubtree(root->right, subRoot);
        return ans;
    }
};
