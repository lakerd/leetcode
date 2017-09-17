class Solution {
    public int distributeCandies(int[] candies) {
        if (candies == null || candies.length == 0)
            return 0;
        HashSet<Integer> sis = new HashSet<>();
        for (int candy : candies) {
            sis.add(candy);
        }
        int half = candies.length / 2;
        if (sis.size() >= half) {
            return half;
        }
        return sis.size();
    }
}