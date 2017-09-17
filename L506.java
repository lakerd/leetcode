public class Solution {
    public String[] findRelativeRanks(int[] nums) {
        if (nums == null || nums.length == 0) return null;
        
        Map<Integer, Integer> m = new HashMap<>();
        
       	int[] a = new int[nums.length];
        
        for (int i = 0; i < nums.length; i++) {
            a[i] = nums[i];
        }
        
        Arrays.sort(a);
        
        int k = 0;
        for (int i = a.length - 1; i >= 0; i--) {
            m.put(a[i], k + 1);
            k++;
        }        
        
        
        String[] output = new String[nums.length];
        int j = 0;
        
        for (int i = 0; i < nums.length; i++) {
             Integer idx = m.get(nums[i]);
             if (idx == 1) {
                 output[j] = "Gold Medal";
             } else if (idx == 2) {
                 output[j] = "Silver Medal";
             } else if (idx == 3) {
                 output[j] = "Bronze Medal";
             } else {
                 output[j] = String.valueOf(idx);
             }
            
            j++;
        }
        return output;
    }
}