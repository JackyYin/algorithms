/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node *, Node *> m;
        
        Node *cur = head;
        Node *newh = NULL;
        Node **pprev = &newh;
        
        while (cur) {
            *pprev = new Node(cur->val);
            (*pprev)->random = cur->random;
            m[cur] = *pprev;
            pprev = &(*pprev)->next;
            cur = cur->next;
        }
        
        pprev = &newh;
        while (pprev && *pprev) {
            if ((*pprev)->random) {
                (*pprev)->random = m[(*pprev)->random];
            }
            pprev = &(*pprev)->next;
        }
        return newh;
    }
};
