class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }
        string prefix = strs[0];
        int len = strs.size();
        for (int i = 1; i < len; ++i) {
            prefix = findPrefix(prefix, strs[i]);
        }
        return prefix;
    }


    string findPrefix(string& s1, string& s2) {
        string res;
        int m = s1.size();
        int n = s2.size();
        for (int i = 0, j = 0; i < m && j < n; ++i, ++j) {
            if (s1[i] != s2[j]) {
                break;
            }
            res.push_back(s1[i]);
        }
        return res;
    }
};
