public class Solution {
    public int findPoisonedDuration(int[] timeSeries, int duration) {
        int total = 0;
        int lastHit = -1;
        for (int i : timeSeries) {
            if (lastHit == -1) {
                lastHit = i;
                total += duration;
            } else {
                if (i - lastHit >= duration) {
                    total += duration;
                } else {
                    total += i - lastHit;
                }
                lastHit = i;
            }
        }
        
        return total;
    }
}