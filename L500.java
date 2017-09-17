public class Solution {
    public String[] findWords(String[] words) {
        if (words == null || words.length == 0)
            return new String[]{};


        HashSet<Character> row1 = new HashSet<>();
        String r1 = "qwertyuiop";
        for (int i = 0; i < r1.length(); i++) {
            row1.add(r1.charAt(i));
        }

        HashSet<Character> row2 = new HashSet<>();
        String r2 = "asdfghjkl";
        for (int i = 0; i < r2.length(); i++) {
            row2.add(r2.charAt(i));
        }

        HashSet<Character> row3 = new HashSet<>();
        String r3 = "zxcvbnm";
        for (int i = 0; i < r3.length(); i++) {
            row3.add(r3.charAt(i));
        }


        ArrayList<String> res = new ArrayList<>();
        HashSet<Character> where;
        for (String word : words) {
            char c = Character.toLowerCase(word.charAt(0));
            if (row1.contains(c))
                where = row1;
            else if (row2.contains(c))
                where = row2;
            else
                where = row3;

            boolean valid = true;
            for (int i = 1; i < word.length(); i++) {
                if (!where.contains(Character.toLowerCase(word.charAt(i)))) {
                    valid = false;
                    break;
                }
            }

            if (valid)
                res.add(word);
        }

        return res.toArray(new String[res.size()]);
    }
}