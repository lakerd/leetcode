class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        
        int t1 = nums[len - 1] * nums[len - 2] * nums[len - 3];
        int t2 = nums[0] * nums[1] * nums[len - 1];
        
                
        return t1 > t2 ? t1 : t2;
    }
};