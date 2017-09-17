public class Solution {
    public int maxCount(int m, int n, int[][] ops) {
        if (ops == null || ops.length == 0) return m * n;
        int row = Integer.MAX_VALUE;
        int col = Integer.MAX_VALUE;
        for (int[] a : ops) {
            row = Math.min(row, a[0]);
            col = Math.min(col, a[1]);
        }
        
        return row * col;
    }
}