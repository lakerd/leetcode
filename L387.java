public class Solution {
    public int firstUniqChar(String s) {
        HashMap<Character, Integer> seen = new HashMap<>();

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (seen.containsKey(c)) {
                seen.put(c, seen.get(c) + 1);
            } else {
                seen.put(c, 0);
            }
        }

        for (int i = 0; i < s.length(); i++) {
            if (seen.containsKey(s.charAt(i)) && seen.get(s.charAt(i)) == 0)
                return s.indexOf(s.charAt(i));
        }

        return -1;
    }
}