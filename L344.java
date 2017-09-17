public class Solution {
    public String reverseString(String s) {
        if (s == null || s.length() == 0) return "";
        char[] arr = s.toCharArray();
        int l = arr.length - 1;
        for (int i = 0; i < arr.length / 2; i++) {
            char tmp = arr[i];
            arr[i] = arr[l];
            arr[l] = tmp;
            l--;
        }
        return String.valueOf(arr);
    }
}