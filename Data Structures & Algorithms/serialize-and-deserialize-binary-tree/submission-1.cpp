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

class Codec {
public:
    string rec(TreeNode* root) {
        if (root == NULL) {
            return "#,";
        }
        string s = "";
        s += to_string(root->val);
        s += ",";
        s += rec(root->left);
        s += rec(root->right);
        return s;
    }

    TreeNode* solve(vector<string>& data, int& n) {
        if (data[n] == "#") {
            n++;
            return NULL;
        }

        TreeNode* root = new TreeNode(stoi(data[n++]));
        root->left = solve(data, n);
        root->right = solve(data, n);
        return root;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = rec(root);
        cout << ans;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> tokens;

        int n = data.size();
        int i = 0;
        while (i < n) {
            string temp = "";
            while (i < n && data[i] != ',') {
                temp += data[i];
                i++;
            }
            tokens.push_back(temp);
            i++;
        }

        int index = 0;
        TreeNode* root = solve(tokens, index);
        return root;
    }
};
