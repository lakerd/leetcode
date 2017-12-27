class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int len = nums.size();
        int sum = 0;
        for (int i = 0; i < len; ++i) {
            sum += nums[i];
        }
        
        if (sum % k != 0) {
            return false;
        }
        
        int targetSum = sum / k;
        set<int> used;
        
        return solve(nums, k, targetSum, 0, 0, used);
    }
    
    bool solve(vector<int>& nums, int k, int targetSum, int currSum, int pos, set<int>& used) {
        if (k == 1) {
            return true;
        }
        if (currSum == targetSum) {
            return solve(nums, k - 1, targetSum, 0, 0, used);
        }
        for (int i = pos; i < nums.size(); ++i) {
            if (used.find(i) == used.end()) {
                used.insert(i);
                if (solve(nums, k, targetSum, currSum + nums[i], i + 1, used)) {
                    return true;
                }
                used.erase(i);
            }
        }
        
        return false;
    }
};
