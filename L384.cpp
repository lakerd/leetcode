class Solution {
public:
    vector<int> ints;
    vector<int> tmp;
    Solution(vector<int> nums) {
        ints = nums;
        tmp = ints;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        tmp = ints;
        return tmp;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        if (tmp.empty()) return tmp;
        for (int i = tmp.size() - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            std::swap(tmp[i], tmp[j]);
        }
        return tmp;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */