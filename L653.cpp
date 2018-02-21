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
    bool findTarget(TreeNode* root, int k) {
        if (root == nullptr) {
            return false;
        }
        unordered_set<int> lookup;
        return dfs(root, k, lookup);
    }
    bool dfs(TreeNode* root, int k, unordered_set<int>& lookup) {
        if (root == nullptr) {
            return false;
        }
        if (lookup.find(k - root->val) != lookup.end()) {
            return true;
        }
        lookup.insert(root->val);
        return dfs(root->left, k, lookup) || dfs(root->right, k, lookup);
    }
};
