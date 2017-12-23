class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        perm(result, n, nums);
        return result;
    }    
    
    void perm(vector<vector<int>>& result, int n, vector<int>& nums) {
        if (n == 1) {
            result.push_back(nums);
        } else {
            for (int i = 0; i < n; ++i) {
                swap(nums, i, n - 1);
                perm(result, n - 1, nums);
                swap(nums, i, n - 1);
            }
        }
    }
    
    void swap(vector<int>& v, int i, int j) {
        int tmp = v[i];
        v[i] = v[j];
        v[j] = tmp;
    }
};
