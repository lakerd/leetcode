public class Solution {
    public int findTargetSumWays(int[] nums, int S) {
        if (nums == null || nums.length == 0) return 0;
        return recur(nums, 0, S, 0, new HashMap<>());
    }
    
    public static int recur(int[] nums, int idx, int S, int current, Map<String, Integer> m) {
        String key = idx + "|" + current;
        
        Integer s = m.get(key);
        if (s != null) return s;
        
        if (idx == nums.length)
            return (current == S) ? 1 : 0;
        
        int s1 = recur(nums, idx + 1, S, current + nums[idx], m);
        int s2 = recur(nums, idx + 1, S, current - nums[idx], m);
        m.put(key, s1 + s2);
        return s1 + s2;
    }
}