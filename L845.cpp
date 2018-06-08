class Solution {
public:
    int longestMountain(vector<int>& A) {
        int len = A.size();
        if (len < 3) {
            return 0;
        }

        int sz = 0;
        int i = 1;
        while (i < len - 1) {
            if (A[i - 1] < A[i] && A[i + 1] < A[i]) {
                int l = i - 1;
                int r = i + 1;
                while (l >= 0 && A[l] < A[l + 1]) l--;
                while (r < len && A[r] < A[r - 1]) r++;
                sz = max(sz, r - l - 1);
                i = r;
            } else {
                ++i;
            }
        }

        if (sz < 3) {
            sz = 0;
        }

        return sz;
    }
};
