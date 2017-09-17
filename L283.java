public class Solution {
    public void moveZeroes(int[] nums) {
        if (nums == null || nums.length == 0) return;
        int i = 0;
        int j = 0;
        int zeroes = 0;
        while (i < nums.length) {
            if (nums[i] != 0) {
                nums[j] = nums[i];
                j++;
            } else {
                zeroes++;
            }
            i++;
        }
        
        for (int x = nums.length - 1; zeroes > 0; x--) { nums[x] = 0; zeroes--; }
    }
}