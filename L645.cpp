class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> lookup;
        int missingNum;
        int repeatedNum;
        for (auto num : nums) {
            lookup[num]++;
            if (lookup[num] == 2) {
                repeatedNum = num;
            }
        }
        int n = nums.size();
        for (int i = 1; i <= n; ++i) {
            if (lookup.find(i) == lookup.end()) {
                missingNum = i;
                break;
            }
        }
        vector<int> result = {repeatedNum, missingNum};
        return result;
    }
};
