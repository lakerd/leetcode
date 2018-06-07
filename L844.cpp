class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> st;
        stack<char> st2;

        for (char c : S) {
            if (c != '#') {
                st.push(c);
            } else {
                if (!st.empty()) {
                    st.pop();
                }
            }
        }

        for (char c : T) {
            if (c != '#') {
                st2.push(c);
            } else {
                if (!st2.empty()) {
                    st2.pop();
                }
            }
        }

        return st == st2;
    }
};
