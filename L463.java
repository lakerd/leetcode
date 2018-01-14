class Solution {
    public int islandPerimeter(int[][] grid) {
        if (grid == null) {
            return 0;
        }
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == 1) {
                    return findSize(grid, i, j);
                }
            }
        }
        return 0;
    }

    private int findSize(int[][] grid, int i, int j) {
        if (i < 0 || j < 0) {
            return 1;
        }
        if (i >= grid.length || j >= grid[0].length) {
            return 1;
        }
        if (grid[i][j] == 0) {
            return 1;
        }
        if (grid[i][j] == -1) {
            return 0;
        }
        int size = 0;
        grid[i][j] = -1;
        size += findSize(grid, i + 1, j);
        size += findSize(grid, i - 1, j);
        size += findSize(grid, i, j + 1);
        size += findSize(grid, i, j - 1);
        return size;
    }
}
