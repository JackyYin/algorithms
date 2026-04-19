/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *skipA = headA;
    struct ListNode *skipB = headB;

    while (skipA != skipB) {
        if (skipA == NULL) {
            skipA = headA;
        } else {
            skipA = skipA->next;
        }
        if (skipB == NULL)
            skipB = headB;
        else
            skipB = skipB->next;
    }
    return skipA;
}
