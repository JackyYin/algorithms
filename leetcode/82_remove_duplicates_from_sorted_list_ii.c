/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *cur = head;
    struct ListNode **ptr = &head;

    while (cur) {
        bool duplicated = false;
        while (cur && cur->next && cur->val == cur->next->val) {
            duplicated = true;
            cur = cur->next;
        }

        cur = cur->next;

        if (duplicated) {
            *ptr = cur;
        }
        else {
            ptr = &(*ptr)->next;
        }

    }
    return head;
}
