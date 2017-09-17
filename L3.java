public class Solution {
    public int lengthOfLongestSubstring(String str) {
        if (str == null || str.length() == 0)
            return 0;
        HashSet<Character> set = new HashSet<>();
        int res = 0;
        int j = 0;
        while (j < str.length()) {
            for (int i = j; i < str.length(); i++) {
                boolean exists = set.contains(str.charAt(i));
                if (exists) {
                    res = Math.max(res, set.size());
                    set.clear();
                    j++;
                    break;
                } else {
                    set.add(str.charAt(i));
                }
            }
        }
        return res;
    }
}