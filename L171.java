public class Solution {
    public int titleToNumber(String s) {
        if (s == null || s.length() == 0) return 0;
        
        String s2 = s.toLowerCase();
        
        if (s2.length() == 1) return s2.charAt(0) - 'a' + 1;
        
        int n = s2.charAt(0) - 'a' + 1;
        
        for (int i = 1; i < s2.length(); i++) {
            n = n * 26 + s2.charAt(i) - 'a' + 1;
        }
        
        return n;
    }
}