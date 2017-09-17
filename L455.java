public class Solution {
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);
        
        int n = 0;
        int c = 0;
        
        for (int i = 0; i < s.length; i++) {
            for (int j = c; j < g.length; j++) {
                if (g[j] <= s[i]) {
                    n++;
                    c = j + 1;
                    break;
                }
            }
        }
        
        return n;
        
    }
}