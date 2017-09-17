public class Solution {
    public String reverseWords(String s) {
        StringBuilder sb = new StringBuilder();
        int start = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == ' ') {
                sb.append(new StringBuilder(s.substring(start, i)).reverse());
                sb.append(" ");
                start = i + 1;
            }
        }

        sb.append(new StringBuilder(s.substring(start)).reverse());

        return sb.toString();
    }
}