class Solution {
public:
    bool validPalindrome(string s) {
        if (s.empty()) {
            return true;
        }
        
        int lo = 0;
        int hi = s.size() - 1;
        
        while (lo < hi) {
            if (s[lo++] != s[hi--]) {
                return isValid(s, lo - 1, hi) || isValid(s, lo, hi + 1);
            }
        }
        
        return true;
    }
    
    bool isValid(string s, int i, int j) {
        while (i < j) {
            if (s[i++] != s[j--]) {
                return false;
            }
        }
        return true;
    }
};
