class Solution {
public:
    vector<int> partitionLabels(string S) {
        int len = S.size();
        vector<int> result;
        if (len == 0) {
            return result;
        }
        unordered_map<char, int> indices;
        for (int i = 0; i < len; ++i) {
            indices[S[i]] = i;
        }
        int i = 0;
        while (i < len) {
            int range = 1;
            int idx = indices[S[i]];
            while (true) {
                bool flag = false;
                for (int j = i; j <= idx; ++j) {
                    if (indices[S[j]] > idx) {
                        idx = indices[S[j]];
                        flag = true;
                    }
                }
                if (!flag) {
                    range = max(range, idx - i + 1);
                    i += range;
                    break;
                }
            }
            result.push_back(range);
        }
        return result;
    }
};
