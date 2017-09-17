public class Solution {
    public String addStrings(String num1, String num2) {
        if (num1 == null || num1.length() == 0) return num2;
        if (num2 == null || num2.length() == 0) return num1;
        
        int len1 = num1.length() - 1;
        int len2 = num2.length() - 1;
        
        StringBuilder sb = new StringBuilder();
        
        int carry = 0;
        
        while (len1 >= 0 || len2 >= 0) {
            int s = 0;
            if (len1 >= 0) { carry += num1.charAt(len1) - '0'; len1--; }
            if (len2 >= 0) { carry += num2.charAt(len2) - '0'; len2--; }
            sb.append(carry % 10);
            carry /= 10;
        }
        
        if (carry > 0) {
            sb.append(1);
        }
        return sb.reverse().toString();
    }
}