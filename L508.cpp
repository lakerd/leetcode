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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr) {
            return ans;
        }
        unordered_map<int, int> sums;

        findSums(root, sums);

        int maxCount = 0;
        int maxSum = 0;
        for (const auto& entry : sums) {
            if (entry.second > maxCount) {
                maxCount = entry.second;
                maxSum = entry.first;
            }
        }

        for (const auto& entry : sums) {
            if (entry.second == maxCount) {
                ans.push_back(entry.first);
            }
        }
        return ans;
    }

    void findSums(TreeNode* root, unordered_map<int, int>& counts) {
        if (root == nullptr) {
            return;
        }

        int s = findSum(root);
        counts[s]++;
        findSums(root->left, counts);
        findSums(root->right, counts);
    }

    int findSum(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return root->val + findSum(root->left) + findSum(root->right);
    }
};
