class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int len = S.size();
        vector<int> res;
        vector<int> dists;

        for (int i = 0; i < len; ++i) {
            if (S[i] == C) {
                dists.push_back(i);
            }
        }

        for (int i = 0; i < len; ++i) {
            int minDist = INT_MAX;
            for (int dist : dists) {
                minDist = min(abs(i - dist), minDist);
            }
            res.push_back(minDist);
        }

        return res;
    }
};
