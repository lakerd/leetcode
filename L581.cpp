class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> copy = nums;
        sort(nums.begin(), nums.end());

        int i = 0;
        int end = copy.size() - 1;

        while (i < copy.size() && copy[i] == nums[i]) i++;
        while (end >= 0 && copy[end] == nums[end]) end--;

        if (i >= end) {
            return 0;
        }
        return end - i + 1;
    }
};
