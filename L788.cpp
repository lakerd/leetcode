class Solution {
public:
    int rotatedDigits(int N) {
        int good = 0;
        for (int i = 1; i <= N; ++i) {
            if (isGood(i)) {
                ++good;
            }
        }
        return good;
    }
    bool isGood(int n) {
        bool isValid = false;
        int orig = n;
        string s = "";
        while (n > 0) {
            int digit = n % 10;
            if (digit == 0 || digit == 1 || digit == 8) {
                isValid = true;
                s += to_string(digit);
            } else if (digit == 2) {
                s += "5";
                isValid = true;
            } else if (digit == 5) { 
                s += "2";
                isValid = true;
            } else if (digit == 6) {
                s += "9";
                isValid = true;
            } else if (digit == 9) {
                s += "6";
                isValid = true;
            } else {
                return false;
            }
            n /= 10;
        }
        reverse(s.begin(), s.end());
        int x = stoi(s);
        return x != orig;
    }
};
