class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int curr = 0;
        if (nums.size() < k) {
            return -1;
        }
        for (int i = 0; i < k; ++i) {
            curr += nums[i];
        }

        double res = (double) curr / k;
        for (int i = k; i < nums.size(); ++i) {
            curr += nums[i];
            curr -= nums[i - k];
            res = max(res, (double) curr / k);
        }

        return res;
    }
};
