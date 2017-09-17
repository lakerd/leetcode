/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null) return head;
        
        ListNode t = head;
        
        while (t != null) {
            if (t.next != null && t.next.val == t.val) {
                ListNode x = t.next;
                while (x != null && x.val == t.val) {
                    x = x.next;
                }
                t.next = x;
            } else {
             t = t.next;   
            }

        }
        
        return head;
    }
}