class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] != 'X') {
                    continue;
                }
                ++ans;
                if (i - 1 >= 0 && board[i - 1][j] == 'X') {
                    --ans;
                } else {
                    while (j < m && board[i][j] == 'X') {
                        ++j;
                    }
                }
            }
        }
        return ans;
    }
};
