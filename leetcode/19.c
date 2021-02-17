struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode **fast = &head;
    struct ListNode **slow = &head;

    for (int i = 1; i <= n; i++) {
        fast = &((*fast)->next);
    }

    while (*fast) {
        fast = &((*fast)->next);
        slow = &((*slow)->next);
    }

    *slow = (*slow)->next;

    return head;
}
