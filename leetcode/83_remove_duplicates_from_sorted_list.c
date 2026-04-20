/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode **ptr = &head;

    for (struct ListNode *node = head; node != NULL && (node)->next != NULL; node=(node)->next) {
        while (node && node->next && (node)->val == (node)->next->val) {
            node = node->next;
        }
        *ptr = node;
        ptr = &(node)->next;
    }
    return head;
}
