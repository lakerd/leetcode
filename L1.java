public class Solution {
    public int[] twoSum(int[] nums, int target) {
		int result[] = new int[2];
		if (nums == null || nums.length == 0)
			return result;
		
		Map<Integer, Integer> hm = new HashMap<>();
		for (int i = 0; i < nums.length; i++) {
			if (hm.containsKey(nums[i])) {
				Integer idx = hm.get(nums[i]);
				return new int[] { idx + 1, i + 1};
			} else {
				hm.put(target - nums[i], i);
			}
		}
		return result;
	}
}