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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bool reverse = false;
        vector<vector<int>> result;
        queue<TreeNode*> q;
        
        if (root == nullptr) return result;
        
        q.push(root);
        
        while (!q.empty()) {
            int count = q.size();
            if (count == 0) break;
            vector<int> current;
            for (int i = 0; i < count; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
                current.push_back(node->val);
            }
            if (reverse) std::reverse(current.begin(), current.end());
            result.push_back(current);
            reverse = !reverse;
        }
        
        return result;
    }
};