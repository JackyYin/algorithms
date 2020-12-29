#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

static inline void addNode (struct ListNode **indirect, int value) {
    struct ListNode *new = malloc(sizeof(struct ListNode));
    new->val = value;
    new->next = NULL;

    while (*indirect) {
        indirect = &((*indirect)->next);
    }

    *indirect = new;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *cur1 = l1, *cur2 = l2, *res = NULL;

    int carry = 0;
    while (cur1 || cur2 || carry) {
        int sum = 0;

        if (cur1) {
            sum += cur1->val;
            cur1 = cur1->next;
        }

        if (cur2) {
            sum += cur2->val;
            cur2 = cur2->next;
        }

        sum += carry;

        carry = sum / 10;
        addNode(&res, sum % 10);
    }

    return res;
}
