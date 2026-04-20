/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
static struct ListNode * split(struct ListNode *head) {
    struct ListNode *slow = head, *fast = head;
    struct ListNode *prev = slow;
    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = NULL;
    return slow;
}

static struct ListNode * mergeSort(struct ListNode *head) {
    struct ListNode *left = head;
    struct ListNode *right = split(head);

    if (left == right)
        return left;

    struct ListNode *l = mergeSort(left);
    struct ListNode *r = mergeSort(right);

    struct ListNode *h = NULL;
    struct ListNode **ptr = &h;
    for (struct ListNode **node = NULL; l && r; *node = (*node)->next) {
        node = (l->val < r->val) ? &l : &r;
        *ptr = *node;
        ptr = &(*node)->next;
    }
    *ptr = (struct ListNode *)((uintptr_t)l | (uintptr_t)r);
    return h;
}

struct ListNode* sortList(struct ListNode* head) {
    if (!head)
        return head;

    return mergeSort(head);
}
