public class Solution {
    public char findTheDifference(String s, String t) {
        int[] letters = new int[26];
        for (char c : s.toCharArray()) letters[c - 'a']++;
        int[] letters2 = new int[26];
        
        for (char c : t.toCharArray()) {
            letters2[c - 'a']++;
        }
        
        
        for (int i = 0; i < letters2.length; i++) {
            if (letters2[i] != letters[i]) return (char)(i + 'a');
        }
        
        return 'a';
    }
}