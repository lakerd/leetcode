/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) {
            return head;
        }

        ListNode *fast = head;

        for (int i = 0; i < n; ++i) {
            fast = fast->next;
        }

        if (fast == nullptr) {
            ListNode *x = head->next;
            delete head;
            return x;
        }

        ListNode *cur = head;

        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next;
            cur = cur->next;
        }

        if (cur->next == nullptr) {
            return head;
        }
        ListNode *x = cur->next;
        cur->next = x->next;
        delete x;
        return head;
    }
};
