public class Solution {
    public boolean detectCapitalUse(String word) {
        boolean allcapitals = true;
        boolean allLowercase = true;
        boolean capitalized = true;
        
        for (int i = 0; i < word.length(); i++) {
            if (!Character.isUpperCase(word.charAt(i))) {
                allLowercase = false;
            } else {
                allcapitals = false;
                if (i != 0) capitalized = false;
            }
        }
        
        return allcapitals || allLowercase || capitalized;
    }
}