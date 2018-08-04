class Solution {
public:
    string toLowerCase(string str) {
        string ans;
        ans.reserve(str.size());
        for (char c : str) {
            if (c >= 'A' && c <= 'Z') {
                ans += (char) (c + 32);
            } else {
                ans += c;
            }
        }
        return ans;
    }
};
