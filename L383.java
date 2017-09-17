public class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        HashMap<Character, Integer> letters = new HashMap<>();
        for (char c : magazine.toCharArray()) {
            Integer total = letters.get(c);
            if (total == null) {
                letters.put(c, 1);
            } else {
                letters.put(c, total + 1);
            }
        }
        
        for (char c : ransomNote.toCharArray()) {
            Integer total = letters.get(c);
            if (total == null) { return false; }
            letters.put(c, total - 1);
            if (total - 1 < 0) { return false; }
        }
        
        return true;
    }
}