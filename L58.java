public class Solution {
    public int lengthOfLastWord(String s) {
        if (s == null || s.length() == 0) return 0;
        String[] ss = s.split(" ");
        if (ss.length == 0) return 0;
        return ss[ss.length - 1].length();
    }
}