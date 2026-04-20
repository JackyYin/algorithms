/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

static struct ListNode * split(struct ListNode *head) {
    struct ListNode *fast = head, *slow = head, *prev = head;

    for (;fast && fast->next;) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = NULL;
    return slow;
}

static struct ListNode *reverse(struct ListNode *head) {
    struct ListNode *ptr = NULL;
    for (struct ListNode *node = head; node;) {
        struct ListNode *next = node->next;
        node->next = ptr;
        ptr = node;
        node = next;
    }
    return ptr;
}


bool isPalindrome(struct ListNode* head) {
    struct ListNode *right = split(head);
    right = reverse(right);

    while (head && right) {
        if (head->val != right->val)
            return false;
        head=head->next;
        right=right->next;
    }
    return true;
}
