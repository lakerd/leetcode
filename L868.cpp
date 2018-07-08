class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int rowSize = A.size();
        int colSize = A[0].size();

        vector<vector<int>> matrix;

        for (int i = 0; i < colSize; ++i) {
            vector<int> row;
            for (int j = 0; j < rowSize; ++j) {
                row.push_back(A[j][i]);
            }
            matrix.push_back(row);
        }
        return matrix;
    }
};
