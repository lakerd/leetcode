class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int len = nums.size();
        unordered_map<int, int> lookup;
        for (int i = 0; i < len; ++i) {
            int n = nums[i];
            auto it = lookup.find(n);
            if (it != lookup.end()) {
                if (abs(it->second - i) <= k) {
                    return true;
                }
                it->second = i;
            } else {
                lookup[n] = i;
            }
        }

        return false;
    }
};
