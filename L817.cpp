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
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> s(G.begin(), G.end());

        int count = 0;
        while (head != nullptr) {
            if (s.count(head->val) && (head->next == nullptr || !s.count(head->next->val))) {
                ++count;
            }
            head = head->next;
        }
        return count;
    }
};
