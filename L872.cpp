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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1;
        vector<int> leaves2;

        findLeaves(root1, leaves1);
        findLeaves(root2, leaves2);
        return leaves1 == leaves2;
    }

    void findLeaves(TreeNode *root, vector<int>& leaves) {
        if (root == nullptr) {
            return;
        }

        if (root->left == nullptr && root->right == nullptr) {
            leaves.push_back(root->val);
        }
        findLeaves(root->left, leaves);
        findLeaves(root->right, leaves);
    }
};
