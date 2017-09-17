public class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
        Comparator<Map.Entry<Integer, Integer>> comparator = new Comparator<Map.Entry<Integer, Integer>>() {
            @Override
            public int compare(Map.Entry<Integer, Integer> o1, Map.Entry<Integer, Integer> o2) {
                return o2.getValue() - o1.getValue();
            }
        };

        PriorityQueue<Map.Entry<Integer, Integer>> entries = new PriorityQueue<>(k, comparator);

        Map<Integer, Integer> m = new HashMap<>();

        for (int num : nums) {
            Integer i = m.get(num);
            if (i == null) {
                m.put(num, 1);
            } else {
                m.put(num, i + 1);
            }
        }

        for (Map.Entry<Integer, Integer> e : m.entrySet()) {
            entries.add(e);
        }

        ArrayList<Integer> result = new ArrayList<>();

        for (int i = 0; i < k; i++) {
            Map.Entry<Integer, Integer> poll = entries.poll();
            result.add(poll.getKey());
        }

        return result;
    }
}