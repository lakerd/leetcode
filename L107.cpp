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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;

        if (root == nullptr) {
            return res;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int len = q.size();
            vector<int> curLevel;
            for (int i = 0; i < len; ++i) {
                TreeNode *n = q.front();
                q.pop();
                curLevel.push_back(n->val);
                if (n->left != nullptr) {
                    q.push(n->left);
                }
                if (n->right != nullptr) {
                    q.push(n->right);
                }
            }
            res.push_back(curLevel);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
