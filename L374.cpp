// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int lo = 1;
        int hi = n;
        
        while (true) {
            int mid = lo + (hi - lo) / 2;
            int num = guess(mid);
            if (num == 0) {
                return mid;
            }
            if (num == 1) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
    }
};
