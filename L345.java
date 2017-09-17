public class Solution {
    public String reverseVowels(String s) {
        if (s.length() == 1) return s;
        
        char[] arr = s.toCharArray();
        
        int l = 0;
        int r = arr.length - 1;
        
        while (l < r) {
            char c1 = arr[l];
            char c2 = arr[r];
            
            if (!isvowel(c1)) {
                l++;
            } else if (!isvowel(c2)) {
                r--;
            } else {
                char tmp = arr[l];
                arr[l] = arr[r];
                arr[r] = tmp;
                l++; r--;
            }
        }
        
        return String.valueOf(arr);
    }
    
    public boolean isvowel(char c) {
        c = Character.toLowerCase(c);
        return c == 'a' || c == 'i' || c == 'e' || c == 'o' || c == 'u';
    }
}