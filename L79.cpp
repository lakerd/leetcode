class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (dfs(i, j, 0, n, m, board, word)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(int i, int j, int idx, int n, int m, vector<vector<char>>& board, const string& word) {
        if (i >= n || j >= m) {
            return false;
        }
        if (i < 0 || j < 0) {
            return false;
        }
        if (board[i][j] != word[idx]) {
            return false;
        }
        int len = word.size() - 1;
        if (idx == len) {
            return true;
        }
        char saved = board[i][j];
        board[i][j] = '|';
        bool found = dfs(i + 1, j, idx + 1, n, m, board, word)
                || dfs(i - 1, j, idx + 1, n, m, board, word)
                || dfs(i, j - 1, idx + 1, n, m, board, word)
                || dfs(i, j + 1, idx + 1, n, m, board, word);
        board[i][j] = saved;
        return found;
    }
};
