class Solution {
public:
    int countSegments(string s) {
        int segments = 0;
        int i = 0;
        int len = s.size();
        while (i < len) {
            if (s[i] != ' ') {
                ++segments;
                while (s[i] != ' ' && i < len) i++;
            } else {
                i++;
            }
        }
        return segments;
    }
};
