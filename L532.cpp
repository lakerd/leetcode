class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int len = nums.size();
        int ans = 0;
        set<pair<int, int>> used;

        for (int i = 0; i < len; ++i) {
            for (int j = i + 1; j < len; ++j) {
                if (abs(nums[i] - nums[j]) == k) {
                    auto p1 = make_pair(nums[i], nums[j]);
                    auto p2 = make_pair(nums[j], nums[i]);
                    if (used.find(p1) == used.end() && used.find(p2) == used.end()) {
                        ans++;
                        used.insert(p1);
                        used.insert(p2);
                    }
                }
            }
        }
        return ans;
    }
};
