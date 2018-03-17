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
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        return validate(root, LONG_MIN, LONG_MAX);
    }

    bool validate(TreeNode* root, long minKey, long maxKey) {
        if (root == nullptr) {
            return true;
        }

        if (root->val <= minKey || root->val >= maxKey) {
            return false;
        }

        return validate(root->left, minKey, root->val)
            && validate(root->right, root->val, maxKey);
    }
};
