public class Solution {
   public List<String> findItinerary(String[][] tickets) {
        HashMap<String, List<String>> hm = new HashMap<>();
        for (String[] ticket : tickets) {
            String from = ticket[0];
            String to = ticket[1];
            if (hm.containsKey(from)) {
                hm.get(from).add(to);
            } else {
                ArrayList<String> lst = new ArrayList<>();
                lst.add(to);
                hm.put(from, lst);
            }
            List<String> h = hm.get(from);
            Collections.sort(h);
        }

        List<String> strings = new ArrayList<>();
        solve("JFK", strings, hm);

        Collections.reverse(strings);
        return strings;
    }

    private static void solve(String start, List<String> strings, Map<String, List<String>> hm) {
        while (hm.containsKey(start) && hm.get(start) != null && !hm.get(start).isEmpty()) {
            String remove = hm.get(start).remove(0);
            solve(remove, strings, hm);
        }
        strings.add(start);
    }

}