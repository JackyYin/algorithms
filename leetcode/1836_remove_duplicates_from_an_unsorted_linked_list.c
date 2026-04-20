/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicatesUnsorted(struct ListNode* head){
    int freq[100001];
    memset(freq, 0, sizeof(freq));

    for (struct ListNode *cur = head; cur != NULL; cur=cur->next)
        freq[cur->val]++;
    
    for (struct ListNode **ptr = &head; *ptr; ) {
        if (*ptr && freq[(*ptr)->val] > 1) {
            *ptr = (*ptr)->next;
        }
        else
            ptr = &(*ptr)->next;
    }
    return head;
}
