#include <queue>
#include <vector>
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
    struct compare {
        bool operator()(const ListNode *l, const ListNode *r) {
            return l->val > r->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        for (auto l : lists) {
            if (l) pq.push(l);
        }

        ListNode *head = nullptr;
        ListNode **cur = &head;

        while (!pq.empty()) {
            ListNode *next = pq.top();
            pq.pop();

            *cur = next;
            cur = &((*cur)->next);

            if (next->next) {
                pq.push(next->next);
            }
        }

        return head;
    }
};
