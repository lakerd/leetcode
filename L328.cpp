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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;

        while (cur) {
            ListNode* nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }

    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }

        if (head->next == nullptr) {
            return head;
        }

        ListNode *odd = head;
        ListNode *even = head->next;

        int i = 3;

        ListNode* cur = head->next->next;

        odd->next = nullptr;
        even->next = nullptr;

        while (cur != nullptr) {
            ListNode* nxt = cur->next;
            if (i % 2 == 0) {
                cur->next = even;
                even = cur;
            } else {
                cur->next = odd;
                odd = cur;
            }
            cur = nxt;
            i++;
        }

        odd = reverse(odd);
        even = reverse(even);

        head = odd;
        while (odd->next != nullptr) {
            odd = odd->next;
        }

        odd->next = even;

        return head;
    }
};
