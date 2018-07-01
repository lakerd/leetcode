/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        solve(root, v);
        return v[k - 1];
    }

    void solve(TreeNode* root, vector<int>& v) {
        if (root == nullptr) {
            return;
        }
        solve(root->left, v);
        v.push_back(root->val);
        solve(root->right, v);
    }
};
