#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* head = NULL;
    struct ListNode** ind = &head;

    while (l1 || l2) {
        struct ListNode* new = malloc(sizeof(struct ListNode));
        if (l1 && l2) {
            if (l1->val < l2->val) {
                new->val = l1->val;
                new->next = NULL;
                l1 = l1->next;
            } else {
                new->val = l2->val;
                new->next = NULL;
                l2 = l2->next;
            }
        } else if (l1) {
            new->val = l1->val;
            new->next = NULL;
            l1 = l1->next;
        } else {
            new->val = l2->val;
            new->next = NULL;
            l2 = l2->next;
        }

        *ind = new;
        ind = &((*ind)->next);
    }

    return head;
}
