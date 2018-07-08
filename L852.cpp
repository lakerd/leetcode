class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int len = A.size();
        for (int i = 0; i < len - 1; ++i) {
            if (A[i + 1] < A[i]) {
                return i;
            }
        }
        return -1;
    }
};
