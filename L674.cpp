class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int longest = 1;
        int cur = 1;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i + 1] > nums[i]) {
                cur++;
                longest = max(cur, longest);
            } else {
                longest = max(cur, longest);
                cur = 1;
            }
        }
        
        return longest;
    }
};
