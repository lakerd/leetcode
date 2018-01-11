class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> index;
        int len = B.size();
        for (int i = 0; i < len; ++i) {
            index[B[i]] = i;
        }
        vector<int> result(len, 0);
        len = A.size();
        for (int i = 0; i < len; ++i) {
            result[i] = index[A[i]];
        }
        return result;
    }
};
