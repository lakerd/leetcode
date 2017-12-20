class Solution {
public:
    bool checkRecord(string s) {
        int A = 0;
        int len = s.size();
        for (int i = 0; i < len; ++i) {
            char c = s[i];
            if (A > 1) {
                return false;
            }
            if (c == 'A') {
                A++;
            } else if (c == 'L') {
                if (i + 1 < len && i + 2 < len && s[i + 1] == 'L' && s[i + 2] == 'L') {
                    return false;
                }
            }
        }
        if (A > 1)
            return false;
        return true;
    }
};
