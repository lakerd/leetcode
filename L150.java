public class Solution {
    public int evalRPN(String[] tokens) {
        if (tokens == null || tokens.length == 0) return 0;
        
        Stack<String> st = new Stack<>();
        
        for (String s : tokens) {
            if ("+".equals(s)) {
                int i2 = Integer.parseInt(st.pop());
                int i1 = Integer.parseInt(st.pop());
                st.push(String.valueOf(i1 + i2));
            } else if ("-".equals(s)) {
                int i2 = Integer.parseInt(st.pop());
                int i1 = Integer.parseInt(st.pop());
                st.push(String.valueOf(i1 - i2));
            } else if ("*".equals(s)) {
                int i2 = Integer.parseInt(st.pop());
                int i1 = Integer.parseInt(st.pop());
                st.push(String.valueOf(i1 * i2));
            } else if ("/".equals(s)) { 
                int i2 = Integer.parseInt(st.pop());
                int i1 = Integer.parseInt(st.pop());
                st.push(String.valueOf(i1 / i2));
            } else {
                st.push(s);
            }
        }
        
        return Integer.parseInt(st.pop());
    }
}