public class Solution {
    public int[] nextGreaterElement(int[] findNums, int[] nums) {
        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < findNums.length; i++) {
            int f = -1;
            int j = 0;
            while (nums[j] != findNums[i] && j < nums.length) j++;
            while (j < nums.length) {
                if (nums[j] > findNums[i]) {
                    f = nums[j];
                    break;
                }
                j++;
            }
            result.add(f);
        }

        int[] ret = new int[result.size()];
        for (int i = 0; i < result.size(); i++) {
            ret[i] = result.get(i);
        }
        return ret;
    }
}