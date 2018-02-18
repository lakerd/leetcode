class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int lo = 0;
        int hi = letters.size() - 1;
        if (letters[hi] <= target) {
            return letters[0];
        }
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (letters[mid] > target) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return letters[lo];
    }
};
