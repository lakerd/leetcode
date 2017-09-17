/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
   	public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
		int rem = 0;
		ListNode head = new ListNode(0);
		ListNode p = head;
		
		while (l1 != null || l2 != null) {
			if (l1 != null) {
				rem += l1.val;
				l1 = l1.next;
			}
			
			if (l2 != null) {
				rem += l2.val;
				l2 = l2.next;
			}
			
			p.next = new ListNode(rem % 10);
			p = p.next;
			rem /= 10;
		}
		if (rem == 1)
		    p.next = new ListNode(1);
		return head.next;
	}
}