public class Solution {
     public static void nqueens(int queenNum, int boardSize, int[] queens, int[] columns, int[] rightDiag, int leftDiag[], List<List<String>> solutions) {
        if (queenNum == boardSize) {
            addsolution(boardSize, queens, solutions);
            return;
        }
        for (int row = 0; row < boardSize; row++) {
            if (columns[row] == 0 && rightDiag[queenNum + row] == 0 && leftDiag[boardSize + queenNum - row] == 0) {
                columns[row] = 1;
                rightDiag[queenNum + row] = 1;
                leftDiag[boardSize + queenNum - row] = 1;
                queens[queenNum] = row;
                nqueens(queenNum + 1, boardSize, queens, columns, rightDiag, leftDiag, solutions);
                columns[row] = 0;
                rightDiag[queenNum + row] = 0;
                leftDiag[boardSize + queenNum - row] = 0;
            }
        }
    }

    private static void addsolution(int boardSize, int[] queens, List<List<String>> solutions) {
        List<String> solution = new ArrayList<String>();
        for (int i = 0; i < boardSize; i++) {
            StringBuilder row = new StringBuilder();
            for (int j = 0; j < boardSize; j++) {
                if (queens[i] == j) {
                    row.append("Q");
                } else {
                    row.append(".");
                }
            }
            solution.add(row.toString());
        }
        solutions.add(solution);
    }
    public List<List<String>> solveNQueens(int n) {
        int boardSize = n;
        int[] col = new int[100];
        Arrays.fill(col, 0);
        int[] rd = new int[2*100 - 1];
        for (int i = 0; i < (2*boardSize - 1); i++) {
            rd[i] = 0;
        }
        int[] ld = new int[100];
        for (int i = 0; i < 2*boardSize; i++) {
            ld[i] = 0;
        }
        int[] queens = new int[100];
        List<List<String>> solutions = new ArrayList<>();
        nqueens(0, boardSize, queens, col, rd, ld, solutions);
        return solutions;
    }
}