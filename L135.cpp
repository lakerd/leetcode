class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        
        int dp[n] = { 0 };
        dp[0] = 1;
        
        for (size_t i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                dp[i] = dp[i - 1] + 1;
            } else {
                dp[i] = 1;
            }
        }
        
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1] && dp[i] <= dp[i + 1]) {
                dp[i] = dp[i + 1] + 1;
            }
        }
        
        int sum = 0;
        for (int i = 0; i < n; ++i) sum += dp[i];
        return sum;
    }
};
