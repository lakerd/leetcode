class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for (int i = left; i <= right; ++i) {
            int n = i;
            bool ok = true;
            while (n != 0) {
                int digit = n % 10;
                if (digit == 0 || (i % digit) != 0) {
                    ok = false;
                    break;
                }
            
                n /= 10;
            }
            if (ok) {
                res.push_back(i);
            }
        }
        return res;
    }
};
