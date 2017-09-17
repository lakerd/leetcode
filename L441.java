public class Solution {
    public int arrangeCoins(int n) {
        if (n == 0) return 0;
        
        int rows = 0;
        int c = 1;
        
        while (n > 0) {
            if (n - c >= 0) {
                n -= c;
                c++;
                rows++;
            } else {
                return rows;
            }
        }
        
        return rows;
    }
}