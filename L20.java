public class Solution {
    public boolean isValid(String s) {
        if (s == null || s.length() == 0) return true;
        
        Stack<Character> st = new Stack<>();
        
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            
            if (c == '(' || c == '[' || c == '{') { st.push(c); continue; }
            
            if (st.isEmpty()) return false;
            
            char p = st.pop();
            
            if (c == ')' && p != '(') return false;
            if (c == '}' && p != '{') return false;
            if (c == ']' && p != '[') return false;
        }
        
        return st.isEmpty();
    }
}