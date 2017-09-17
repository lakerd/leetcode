public class Solution {
    public void sortColors(int[] nums) {
        if (nums == null || nums.length == 0) return;

        int low = 0;
        int mid = 0;
        int high = nums.length - 1;

        while (mid <= high) {
            if      (nums[mid] == 0) { swap(nums, low++, mid++); }
            else if (nums[mid] == 2) { swap(nums, mid, high--); }
            else if (nums[mid] == 1) { mid++; }
        }
    }
    
    
    private static void swap(int[] a, int i, int j) {
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }
}