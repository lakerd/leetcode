public class Solution {
    public int myAtoi(String str) {
		if (str == null || str.length() == 0)
			return 0;
		String trimmed = str.trim();
		boolean is_neg = false;
		boolean sign = false;
		char[] arr = trimmed.toCharArray();
		if (arr[0] == '-') {
			is_neg = true;
			sign = true;
		} else if (arr[0] == '+') {
		    is_neg = false;
		    sign = true;
		} else {
		    sign = false;
		}
		double x = 0;
		int startIdx = sign ? 1 : 0;
		for (int i = startIdx; i < arr.length; i++) {
			if (arr[i] >= '0' && arr[i] <= '9') {
				x = (x * 10) + arr[i] - '0';
			} else {
			   break;
			}
		}
		if (is_neg)
			x *= -1;
		if (x > Integer.MAX_VALUE)
			return Integer.MAX_VALUE;
		if (x < Integer.MIN_VALUE)
			return Integer.MIN_VALUE;
		return (int) x;
    }
}