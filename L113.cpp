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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }
       
        vector<int> path;
        dfs(result, root, sum, path, 0);
        return result;
    }
    
    void dfs(vector<vector<int>>& result, TreeNode* node, int sum, vector<int>& path, int curSum) {
        if (node == nullptr) {
            return;
        }
        
        curSum += node->val;
        path.push_back(node->val);
        if (node->left == nullptr && node->right == nullptr && curSum == sum) {
            result.push_back(path);
        }
        
        dfs(result, node->left, sum, path, curSum);
        dfs(result, node->right, sum, path, curSum);
        path.pop_back();
    }
};
