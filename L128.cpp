class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> lookup;
        lookup.insert(nums.begin(), nums.end());
        int longest = 0;

        for (int num : nums) {
            int cur = 0;
            if (lookup.find(num - 1) == lookup.end()) {
                int n = num;
                while (lookup.find(n) != lookup.end()) {
                    ++cur;
                    ++n;
                }
                longest = max(cur, longest);
            }
        }

        return longest;
    }
};
