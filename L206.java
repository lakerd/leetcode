/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode reverseList(ListNode head) {
        if (head == null)
            return head;
        ListNode tmp = new ListNode(head.val);
        tmp.next = null;
        head = head.next;
        while (head != null) {
            ListNode t = new ListNode(head.val);
            t.next = tmp;
            head = head.next;
            tmp = t;
        }
        return tmp;
    }
}