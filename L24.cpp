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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        if (head->next == nullptr) {
            return head;
        }
        ListNode* newhead = nullptr;
        ListNode* prev = nullptr;
        bool flag = false;
        while (head != nullptr) {
            ListNode* nxt = head->next;
            ListNode* cur = head;
            if (nxt != nullptr) {
                cur->next = nxt->next;
                nxt->next = cur;
                if (!flag) {
                    newhead = nxt;
                    flag = true;
                }
                if (prev != nullptr) {
                    prev->next = nxt;
                }
                prev = cur;
                head = cur->next;
            } else {
                head = head->next;
            }
        }
        return newhead;
    }
};
