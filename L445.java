/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        Stack<ListNode> s1 = new Stack<>();
        Stack<ListNode> s2 = new Stack<>();
        
        
        ListNode cur = l1;
        while (cur != null) {
            s1.push(cur);
            cur = cur.next;
        }
        
        cur = l2;
        
        while (cur != null) {
            s2.push(cur);
            cur = cur.next;
        }
        
        
        int carry = 0;
        ListNode head = new ListNode(0);
        while (!s1.isEmpty() || !s2.isEmpty()) {
            int sum = 0;
            if (!s1.isEmpty()) carry += s1.pop().val;
            if (!s2.isEmpty()) carry += s2.pop().val;
            head.val = carry % 10;
            carry /= 10;
            ListNode ln = new ListNode(carry);
            ln.next = head;
            head = ln;
        }


        return head.val == 0 ? head.next : head;
    }
}