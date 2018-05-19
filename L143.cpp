#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
    public:
        void reorderList(ListNode* head) {
            if (head == nullptr) return;
            if (head->next == nullptr) return;

            int len = 0;
            ListNode *cur = head;
            while (cur) {
                len++;
                cur = cur->next;
            }

            cur = head;
            int mid = len / 2;
            while (mid--) {
                cur = cur->next;
            }

            ListNode* nxt = cur->next;
            cur->next = nullptr;

            stack<ListNode*> st;
            while (nxt) {
                st.push(nxt);
                nxt = nxt->next;
            }

            cur = head;

            while (!st.empty() && cur) {
                ListNode *n = st.top();
                st.pop();
                ListNode *nxt = cur->next;
                cur->next = n;
                n->next = nxt;
                cur = nxt;
            }
        }
};

int main()
{
    ListNode *a = new ListNode(4);
    ListNode *b = new ListNode(3);
    b->next = a;
    ListNode *c = new ListNode(2);
    c->next = b;
    ListNode *d = new ListNode(1);
    d->next = c;
    Solution s;
    s.reorderList(d);

    for (; d != nullptr; d = d->next) {
        cout << d->val << endl;
    }
    return 0;
}
