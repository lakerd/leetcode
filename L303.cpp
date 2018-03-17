class NumArray {
public:
    vector<int> blocks;
    vector<int> a;
    int len;
    NumArray(vector<int> nums) {
        a = nums;
        int n = nums.size();
        len = (int) sqrt(n + .0) + 1;
        blocks.reserve(len);
        blocks.assign(len, 0);
        for (int i = 0; i < n; ++i) {
            blocks[i / len] += a[i];
        }
    }

    int sumRange(int i, int j) {
        int sum = 0;
        for (int k = i; k <= j; ) {
            if (k % len == 0 && k + len - 1 <= j) {
                sum += blocks[k / len];
                k += len;
            } else {
                sum += a[k];
                ++k;
            }
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
