public class Solution {
    public int reverse(int n) {
		if (n == 0) return 0;
		boolean is_neg = n < 0;
		n = Math.abs(n);
		long res = 0;
		while (n > 0) {
			int digit = n % 10;
			n /= 10;
			res *= 10;
			res += digit;
		}
		
		if (res > Integer.MAX_VALUE)
			return 0;
		if (res < Integer.MIN_VALUE)
			return 0;
		
		return is_neg ? (int)-res : (int)res;
    }
}