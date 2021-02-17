#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        stack<ListNode *> stk;

        ListNode *cur = head;
        while (cur) {
            stk.push(cur);
            cur = cur->next;
        }

        int cnt = 1;
        while (cnt < n - 1) {
            stk.pop();
            cnt++;
        }

        ListNode *next = nullptr;
        if (cnt == n - 1) {
            next = stk.top();
            stk.pop();
        }

        // remove element n
        stk.pop();

        if (stk.size() > 0) {
            ListNode *prev = stk.top();
            prev->next = next;
        } else {
            head = next;
        }

        return head;
    }
};
