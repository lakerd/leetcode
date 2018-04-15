#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root = buildtree(nums, 0, nums.size() - 1);
        return root;
    }

    TreeNode* buildtree(vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        int maxIdx = left;
        for (int i = left + 1; i <= right; ++i) {
            if (nums[i] > nums[maxIdx]) {
                maxIdx = i;
            }
        }
        TreeNode* n = new TreeNode(nums[maxIdx]);
        n->left = buildtree(nums, left, maxIdx - 1);
        n->right = buildtree(nums, maxIdx + 1, right);
        return n;
    }
};

void printTree(TreeNode *t) {
    if (t == nullptr) {
        return;
    }
    cout << t->val << endl;
    printTree(t->left);
    printTree(t->right);
}

int main()
{
    vector<int> nums = {3,2,1,6,0,5};
    Solution s;
    TreeNode* t = s.constructMaximumBinaryTree(nums);

    printTree(t);
    return 0;
}

