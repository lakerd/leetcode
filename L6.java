public class Solution {
    public String convert(String s, int nrows) {
        if (s == null || s.length() == 0)
            return s;
        if (nrows < 2)
            return s;

        StringBuilder sb[] = new StringBuilder[nrows];
        for (int i = 0; i < sb.length; i++) sb[i] = new StringBuilder();

        int row = 0;
        boolean dir = true;
        for (int i = 0; i < s.length(); i++) {
            sb[row].append(s.charAt(i));

            if (row == 0)
                dir = true;
            if (row == nrows - 1)
                dir = false;

            row = dir ? row + 1 : row - 1;
        }

        StringBuilder res = new StringBuilder();
        for (StringBuilder sbb : sb)
            res.append(sbb.toString());
        return res.toString();
    }
}