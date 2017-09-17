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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) return head;
        ListNode* orig = head;
        ListNode* prev = nullptr;
        while (head != nullptr) {
            ListNode* next = head->next;
            if (head->val == val) {
                if (orig == head) orig = orig->next;
                if (prev) {
                    prev->next = next;
                }
            } else {
                prev = head;
            }
            
            head = head->next;
        }
        
        return orig;
    }
};