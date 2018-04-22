class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> result;
        dfs(0, S, result);

        return result;
    }

    void dfs(int pos, string s, vector<string>& result) {
        int len = s.size();
        if (pos == len) {
            result.push_back(s);
            return;
        }

        if (s[pos] >= '0' && s[pos] <= '9') {
            dfs(pos + 1, s, result);
        } else {
            s[pos] = tolower(s[pos]);
            dfs(pos + 1, s, result);

            s[pos] = toupper(s[pos]);
            dfs(pos + 1, s, result);
        }
    }
};
