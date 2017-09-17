public class Solution {
    public int climbStairs(int n) {
        int[] a = new int[n + 1];
        return solve(n, a);
    }
    
    public int solve(int n, int[] a) {
        if (n < 3) return n;
        if (a[n] != 0) return a[n];
        a[n] = solve(n - 1, a) + solve(n - 2, a);
        return a[n];
    }
}