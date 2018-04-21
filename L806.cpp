class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int lines = 1;
        int curWidth = 0;
        for (char c : S) {
            int letterWidth = widths[c - 'a'];
            if (curWidth + letterWidth > 100) {
                lines++;
                curWidth = letterWidth;
            } else {
                curWidth += letterWidth;
            }
        }
        vector<int> result = {lines, curWidth};
        return result;
    }
};
