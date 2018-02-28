class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        int maxidx = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > nums[maxidx]) {
                maxidx = i;
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (maxidx != i && nums[i] * 2 > nums[maxidx]) {
                return -1;
            }
        }
        return maxidx;
    }
};
