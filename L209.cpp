class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        int sum = 0;
        int ans = INT_MAX;
        int left = 0;
        int len = nums.size();

        for (int i = 0; i < len; ++i) {
            sum += nums[i];
            
            while (sum >= s) {
                ans = min(ans, i - left + 1);
                sum -= nums[left];
                left++;
            }

        }
        
        if (ans == INT_MAX) {
            return 0;   
        }
        return ans;
    }
};
