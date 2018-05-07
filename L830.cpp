class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        int len = S.size();
        vector<vector<int>> res;

        int i = 0 ;
        while (i < len) {
            char c = S[i];
            int sz = 0;
            int start = i;

            while (S[i] == c && i < len) {
                i++;
                sz++;
            }

            if (sz >= 3) {
                res.push_back({start, i - 1});
            }
        }

        return res;
    }
};
