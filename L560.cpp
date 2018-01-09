class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {     
        unordered_map<int, int> prefixSum;
        prefixSum[0] = 1;
        
        int sum = 0;
        int ans = 0;
        
        for (auto num : nums) {
            sum += num;
            ans += prefixSum[sum - k];
            prefixSum[sum]++;
        }

        return ans;
    }
};
