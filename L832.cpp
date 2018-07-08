class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        vector<vector<int>> img;
        int rowSize = A.size();
        int colSize = A[0].size();

        for (int i = 0; i < rowSize; ++i) {
            vector<int> row;
            for (int j = 0; j < colSize; ++j) {
                row.push_back(A[i][j]);
            }
            reverse(row.begin(), row.end());
            for (int k = 0; k < (int) row.size(); ++k) {
                row[k] = (row[k] == 0) ? 1 : 0;
            }
            img.push_back(row);
        }
        return img;
    }
};
