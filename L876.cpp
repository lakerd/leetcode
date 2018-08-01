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
    ListNode* middleNode(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }

        int len = 0;
        ListNode *tmp = head;
        while (tmp != nullptr) {
            len++;
            tmp = tmp->next;
        }

        int mid = len / 2;
        for (int i = 0; i < mid; ++i) {
            head = head->next;
        }

        return head;
    }
};
