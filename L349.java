class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        if (nums1 == null || nums1.length == 0) return new int[]{};
        if (nums2 == null || nums2.length == 0) return new int[]{};
        
        Set<Integer> set = new HashSet<>();
        for (int num : nums1) set.add(num);
        
        List<Integer> result = new ArrayList<>();
        
        
        for (int num : nums2) {
            if (set.contains(num) && !result.contains(num)) {
                result.add(num);
            }
        }
        
        int[] res = new int[result.size()];
        
        for (int i = 0; i < result.size(); i++) {
            res[i] = result.get(i);
        }
        
        return res;
    }
}