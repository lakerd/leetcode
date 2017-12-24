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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) {
            return nullptr;
        }
        
        return toBST(nums, 0, nums.size());
    }
    
    TreeNode* toBST(vector<int>& nums, int left, int right) {
        if (left >= right) {
            return nullptr;
        }
        int mid = (left + right) / 2;
        TreeNode* t = new TreeNode(nums[mid]);
        t->left = toBST(nums, left, mid);
        t->right = toBST(nums, mid + 1, right);
        return t;
    }
};
