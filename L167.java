public class Solution {
    public int[] twoSum(int[] numbers, int target) {
        if (numbers == null || numbers.length == 0) return new int[]{};
        
        int lo = 0;
        int hi = numbers.length - 1;
        
        while (lo < hi) {
            int l = numbers[lo];
            int r = numbers[hi];
            int sum = l + r;
            if (sum == target) {
                return new int[]{ lo + 1, hi + 1};
            } else if (sum < target) {
                lo++;
            } else {
                hi--;
            }
        }
        
        return new int[]{ lo + 1, hi + 1};
    }
}