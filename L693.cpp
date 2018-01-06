class Solution {
public:
    bool hasAlternatingBits(int n) {
        if (n == 0) {
            return false;
        }

        int prev = n & 1;

        while (n > 0) {
            n >>= 1;
            int cur = n & 1;
            if (cur == prev) {
                return false;
            }
            prev = cur;
        }

        return true;
    }
};
