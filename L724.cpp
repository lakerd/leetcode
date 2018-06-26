class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.empty()) {
            return -1;
        }

        int sum = 0;
        for (int n : nums) {
            sum += n;
        }

        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            int cur = 0;
            for (int j = 0; j < i; ++j) {
                cur += nums[j];
            }

            if (cur == (sum - cur - nums[i])) {
                return i;
            }
        }

        return -1;
    }
};
