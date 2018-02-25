class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int rowSize = matrix.size();
        int colSize = matrix[0].size();
        for (int col = colSize - 1; col >= 0; --col) {
            for (int row = 0; row < rowSize; ++row) {
                int first = matrix[row][col];
                for (int i = row, j = col; i < rowSize && j < colSize; ++i, ++j) {
                    if (matrix[i][j] != first) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
